// Cyphesis Online RPG Server and AI Engine
// Copyright (C) 2009 Alistair Riddoch
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA


#ifdef NDEBUG
#undef NDEBUG
#endif
#ifndef DEBUG
#define DEBUG
#endif

#include "../TestBase.h"

#include "rules/simulation/WorldRouter.h"

#include "server/EntityBuilder.h"
#include "server/EntityRuleHandler.h"
#include "server/EntityFactory.h"

#include "rules/Domain.h"
#include "rules/simulation/World.h"

#include "common/const.h"
#include "common/globals.h"
#include "common/id.h"
#include "common/Inheritance.h"
#include "common/log.h"
#include "common/Monitors.h"
#include "common/SystemTime.h"
#include "common/operations/Tick.h"
#include "common/Variable.h"

#include <Atlas/Objects/Anonymous.h>

#include <cstdio>
#include <cstdlib>

#include <cassert>
#include <server/Ruleset.h>

#include "../DatabaseNull.h"
#include "../TestPropertyManager.h"

using Atlas::Message::Element;
using Atlas::Message::MapType;
using Atlas::Objects::Entity::Anonymous;
using Atlas::Objects::Entity::RootEntity;
using Atlas::Objects::Operation::Tick;

Atlas::Objects::Factories factories;

struct WorldRouterintegration : public Cyphesis::TestBase
{

    Inheritance* m_inheritance;
    EntityBuilder* m_eb;
    DatabaseNull m_database;

    void setup() override;

    void teardown() override;

    void test_sequence();

    void test_creationAndDeletion() {
        {
            Ref<LocatedEntity> base = new Entity("", 0);
            std::unique_ptr<WorldRouter> test_world(new WorldRouter(base, *m_eb, {}));

            Anonymous ent;
            ent->setLoc("0");
            auto ent1 = test_world->addNewEntity("thing", ent);

            ASSERT_EQUAL(2, test_world->m_entityCount);

            test_world->delEntity(ent1.get());
            //A single entity when removed should have all references removed too.
            ASSERT_EQUAL(1, test_world->m_entityCount);
            ASSERT_EQUAL(1, ent1->checkRef());
        }

        {
            Ref<LocatedEntity> base = new Entity("", 0);
            std::unique_ptr<WorldRouter> test_world(new WorldRouter(base, *m_eb, {}));

            Anonymous ent;
            ent->setLoc("0");
            auto ent1 = test_world->addNewEntity("thing", ent);

            ASSERT_EQUAL(2, test_world->m_entityCount);

            Anonymous ent2_arg{};
            ent2_arg->setLoc(ent1->getId());
            auto ent2 = test_world->addNewEntity("thing", ent2_arg);

            ASSERT_EQUAL(3, test_world->m_entityCount);
            //Make sure ent2 is a child of ent1.
            ASSERT_EQUAL(ent2->m_location.m_parent.get(), ent1.get());

            //Make sure that a child when removed has all references removed too.
            test_world->delEntity(ent2.get());
            ASSERT_EQUAL(2, test_world->m_entityCount);
            ASSERT_EQUAL(1, ent2->checkRef());

        }
    }


    WorldRouterintegration() {
        ADD_TEST(WorldRouterintegration::test_sequence);
        ADD_TEST(WorldRouterintegration::test_creationAndDeletion);

    }

};


void WorldRouterintegration::setup()
{
    m_inheritance = new Inheritance(factories);
    m_eb = new EntityBuilder();
    TestPropertyManager propertyManager;

    class TestEntityRuleHandler : public EntityRuleHandler
    {
        public:
            explicit TestEntityRuleHandler(EntityBuilder& eb, const PropertyManager& propertyManager) : EntityRuleHandler(eb, propertyManager)
            {}

            int test_installEntityClass(const std::string& class_name,
                                        const std::string& parent,
                                        const Atlas::Objects::Root& class_desc,
                                        std::string& dependent,
                                        std::string& reason,
                                        std::unique_ptr<EntityFactoryBase> factory)
            {
                std::map<const TypeNode*, TypeNode::PropertiesUpdate> changes;
                return installEntityClass(class_name, parent, class_desc, dependent, reason, std::move(factory), changes);
            }
    };

    TestEntityRuleHandler entityRuleHandler(*m_eb, propertyManager);

    auto composeDeclaration = [](std::string class_name, std::string parent, Atlas::Message::MapType rawAttributes) {

        Atlas::Objects::Root decl;
        decl->setObjtype("class");
        decl->setId(class_name);
        decl->setParent(parent);

        Atlas::Message::MapType composed;
        for (const auto& entry : rawAttributes) {
            composed[entry.first] = Atlas::Message::MapType{
                {"default", entry.second}
            };
        }

        decl->setAttr("attributes", composed);
        return decl;
    };
    std::string dependent, reason;
    {
        auto decl = composeDeclaration("thing", "game_entity", {});
        entityRuleHandler.test_installEntityClass(decl->getId(), decl->getParent(), decl, dependent, reason, std::make_unique<EntityFactory<Thing>>());
    }
    {
        auto decl = composeDeclaration("character", "thing", {});
        entityRuleHandler.test_installEntityClass(decl->getId(), decl->getParent(), decl, dependent, reason, std::make_unique<EntityFactory<Thing>>());
    }
}

void WorldRouterintegration::teardown()
{
    delete m_eb;
    delete m_inheritance;
}

void WorldRouterintegration::test_sequence()
{
    Ref<Entity> base = new Entity("", 0);
    WorldRouter* test_world = new WorldRouter(base, *m_eb, {});

    auto ent1 = test_world->addNewEntity("__no_such_type__",
                                                   Anonymous());
    assert(!ent1);

    Anonymous ent;
    ent->setLoc("0");
    ent1 = test_world->addNewEntity("thing", ent);
    assert(ent1);

    std::string id;
    long int_id = newId(id);

    Entity* ent2 = new Thing(id, int_id);
    assert(ent2 != 0);
    ent2->m_location.m_pos = Point3D(0, 0, 0);
    test_world->addEntity(ent2, base);

    Tick tick;
    tick->setFutureSeconds(0);
    tick->setTo(ent2->getId());
    test_world->message(tick, *ent2);


    test_world->delEntity(base.get());
//    test_world->delEntity(ent4);
//    ent4 = 0;

    delete test_world;
}

int main()
{
    WorldRouterintegration t;

    t.m_database.idGeneratorFn = []() {
        static long id = 0;
        return ++id;
    };


    return t.run();
}

// stubs

#include "server/EntityFactory.h"
#include "server/ArchetypeFactory.h"
#include "rules/simulation/CorePropertyManager.h"

#include "rules/simulation/AreaProperty.h"
#include "rules/AtlasProperties.h"
#include "rules/BBoxProperty.h"
#include "rules/simulation/CalendarProperty.h"
#include "rules/simulation/EntityProperty.h"
#include "rules/simulation/StatusProperty.h"
#include "rules/simulation/TasksProperty.h"
#include "rules/simulation/TerrainProperty.h"
#include "rules/simulation/DomainProperty.h"

#include "rules/simulation/ExternalMind.h"
#include "rules/simulation/Task.h"

#include "rules/python/PythonScriptFactory.h"

#define STUB_PythonScriptFactory_PythonScriptFactory

template<>
PythonScriptFactory<LocatedEntity>::PythonScriptFactory(const std::string& p,
                                                        const std::string& t) :
    PythonClass(p, t)
{
}

template<>
int PythonScriptFactory<LocatedEntity>::setup()
{
    return load();
}

#include "../stubs/rules/stubBBoxProperty.h"
#include "../stubs/rules/simulation/stubTasksProperty.h"
#include "../stubs/rules/simulation/stubTerrainProperty.h"
#include "../stubs/rules/simulation/stubDomainProperty.h"
#include "../stubs/rules/ai/stubBaseMind.h"
#include "../stubs/rules/stubMemEntity.h"
#include "../stubs/rules/ai/stubMemMap.h"
#include "../stubs/rules/simulation/stubPropelProperty.h"
#include "../stubs/rules/python/stubPythonClass.h"
#include "../stubs/rules/simulation/stubPedestrian.h"
#include "../stubs/rules/simulation/stubMovement.h"
#include "../stubs/rules/stubLocation.h"
#include "../stubs/rules/simulation/stubUsagesProperty.h"
#include "../stubs/rules/entityfilter/stubFilter.h"

#include "../stubs/common/stubOperationsDispatcher.h"
#include "../stubs/common/stubScriptKit.h"
#include "../stubs/common/stubRouter.h"
#include "../stubs/server/stubConnectableRouter.h"
#include "../stubs/server/stubAccount.h"
#include "../stubs/server/stubPlayer.h"
#include "../stubs/server/stubExternalMindsManager.h"
#include "../stubs/server/stubExternalMindsConnection.h"
#include "../stubs/server/stubServerRouting.h"
#include "../stubs/server/stubLobby.h"
#include "../stubs/rules/simulation/stubEntityProperty.h"
#include "../stubs/rules/python/stubPythonScriptFactory.h"

#include "../stubs/common/stubMonitors.h"

#include <Atlas/Objects/Operation.h>
#include "../stubs/rules/python/stubScriptsProperty.h"

#define STUB_CorePropertyManager_addProperty
std::unique_ptr<PropertyBase> CorePropertyManager::addProperty(const std::string & name) const
{
    return std::make_unique<Property<float>>();
}

#include "../stubs/rules/simulation/stubCorePropertyManager.h"


#define STUB_ArchetypeFactory_newEntity

Ref<Entity> ArchetypeFactory::newEntity(const std::string& id, long intId, const Atlas::Objects::Entity::RootEntity& attributes)
{
    return new Entity(id, intId);
}

#include "../stubs/server/stubArchetypeFactory.h"


class World;


#include "../stubs/rules/simulation/stubAreaProperty.h"
#include "../stubs/rules/simulation/stubCalendarProperty.h"
#include "../stubs/rules/simulation/stubWorldTimeProperty.h"
#include "../stubs/rules/simulation/stubVoidDomain.h"

#define STUB_IdProperty_get

int IdProperty::get(Atlas::Message::Element& val) const
{
    val = m_data;
    return 0;
}

#include "../stubs/rules/simulation/stubTask.h"
#include "../stubs/rules/stubAtlasProperties.h"
#include "../stubs/rules/simulation/stubStatusProperty.h"
#include "../stubs/rules/simulation/stubModeDataProperty.h"
#include "../stubs/rules/simulation/stubModeProperty.h"

#define STUB_ExternalMind_linkUp

void ExternalMind::linkUp(Link* c)
{
    m_link = c;
}

#include "../stubs/rules/simulation/stubExternalMind.h"

sigc::signal<void> python_reload_scripts;

#if 0

int timeoffset = 0;

namespace consts {
const char * rootWorldId = "0";
const long rootWorldIntId = 0L;
}

namespace Atlas { namespace Objects { namespace Operation {
int TICK_NO = -1;
}}}

SoftProperty::SoftProperty()
{
}

SoftProperty::SoftProperty(const Element & data) :
              PropertyBase(0), m_data(data)
{
}

int SoftProperty::get(Element & val) const
{
    val = m_data;
    return 0;
}

void SoftProperty::set(const Element & val)
{
}

SoftProperty * SoftProperty::copy() const
{
    return 0;
}

PropertyBase::PropertyBase(unsigned int flags) : m_flags(flags)
{
}

PropertyBase::~PropertyBase()
{
}

void PropertyBase::install(LocatedEntity *, const std::string & name)
{
}

void PropertyBase::remove(LocatedEntity *, const std::string & name)
{
}

void PropertyBase::apply(LocatedEntity *)
{
}

void PropertyBase::add(const std::string & s,
                       MapType & ent) const
{
    get(ent[s]);
}

void PropertyBase::add(const std::string & s,
                       const Atlas::Objects::Entity::RootEntity & ent) const
{
}

HandlerResult PropertyBase::operation(LocatedEntity *,
                                      const Operation &,
                                      OpVector &)
{
    return OPERATION_IGNORED;
}

template<>
void Property<int>::set(const Element & e)
{
    if (e.isInt()) {
        this->m_data = e.asInt();
    }
}

template<>
void Property<double>::set(const Element & e)
{
    if (e.isNum()) {
        this->m_data = e.asNum();
    }
}

template<>
void Property<std::string>::set(const Element & e)
{
    if (e.isString()) {
        this->m_data = e.String();
    }
}

template class Property<int>;
template class Property<double>;
template class Property<std::string>;

#include "stubs/common/stubRouter.h"
#include "stubs/common/stubid.h"
#include "stubs/common/stublog.h"

static long idGenerator = 0;

long newId(std::string & id)
{
    static char buf[32];
    long new_id = ++idGenerator;
    sprintf(buf, "%ld", new_id);
    id = buf;
    assert(!id.empty());
    return new_id;
}

#ifndef STUB_BaseWorld_getEntity
#define STUB_BaseWorld_getEntity
Ref<LocatedEntity> BaseWorld::getEntity(const std::string & id) const
{
    return getEntity(integerId(id));
}

Ref<LocatedEntity> BaseWorld::getEntity(long id) const
{
    auto I = m_eobjects.find(id);
    if (I != m_eobjects.end()) {
        assert(I->second);
        return I->second;
    } else {
        return nullptr;
    }
}
#endif //STUB_BaseWorld_getEntity

#include "stubs/rules/simulation/stubBaseWorld.h"

Inheritance * Inheritance::m_instance = nullptr;

Inheritance::Inheritance() : noClass(0)
{
}

Inheritance & Inheritance::instance()
{
    if (m_instance == nullptr) {
        m_instance = new Inheritance();
    }
    return *m_instance;
}

const TypeNode * Inheritance::getType(const std::string & parent) const
{
    auto I = atlasObjects.find(parent);
    if (I == atlasObjects.end()) {
        return 0;
    }
    return I->second;
}

VariableBase::~VariableBase()
{
}

template <typename T>
Variable<T>::Variable(const T & variable) : m_variable(variable)
{
}

template <typename T>
Variable<T>::~Variable()
{
}

template <typename T>
void Variable<T>::send(std::ostream & o)
{
    o << m_variable;
}

template class Variable<int>;

Monitors * Monitors::m_instance = nullptr;

Monitors::Monitors()
{
}

Monitors::~Monitors()
{
}

Monitors * Monitors::instance()
{
    if (m_instance == nullptr) {
        m_instance = new Monitors();
    }
    return m_instance;
}

void Monitors::watch(const::std::string & name, VariableBase * monitor)
{
}
#endif // 0
