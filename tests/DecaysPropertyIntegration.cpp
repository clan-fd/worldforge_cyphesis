// Cyphesis Online RPG Server and AI Engine
// Copyright (C) 2013 Alistair Riddoch
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

#include "TestBase.h"

#include "rulesets/Entity.h"
#include "rulesets/DecaysProperty.h"

#include "common/OperationRouter.h"
#include "common/PropertyFactory_impl.h"
#include "rulesets/BaseWorld.h"

#include <Atlas/Objects/Operation.h>

using Atlas::Message::MapType;
using Atlas::Objects::Operation::Delete;

#include "TestWorld.h"

class DecaysPropertyintegration : public Cyphesis::TestBase
{
  private:
    Ref<Entity> m_world;
    Ref<Entity> m_entity;
    PropertyBase * m_property;
  public:
    DecaysPropertyintegration();

    void setup();
    void teardown();

    void test_handler();
};

DecaysPropertyintegration::DecaysPropertyintegration()
{
    ADD_TEST(DecaysPropertyintegration::test_handler);
}

void DecaysPropertyintegration::setup()
{
    m_world = new Entity("0", 0);
    new TestWorld(m_world);

    m_entity = new Entity("1", 1);
    m_entity->m_location.m_parent = m_world;

    PropertyFactory<DecaysProperty> decays_property_factory;

    m_property = decays_property_factory.newProperty();
    m_property->install(m_entity.get(), "decays");
    m_entity->setProperty("decays", m_property);
}

void DecaysPropertyintegration::teardown()
{
}

void DecaysPropertyintegration::test_handler()
{
    Delete d;

    OpVector res;
    m_entity->operation(d, res);

    ASSERT_EQUAL(res.size(), 1u);
    const Operation & reply = res.front();
    ASSERT_EQUAL(reply->getClassNo(), Atlas::Objects::Operation::CREATE_NO);
    ASSERT_EQUAL(reply->getTo(), m_world->getId());
}

int main()
{
    DecaysPropertyintegration t;

    return t.run();
}

// stubs

#include "rulesets/AtlasProperties.h"
#include "rulesets/Domain.h"
#include "rulesets/Script.h"

#include "rulesets/BaseWorld.h"
#include "common/id.h"
#include "common/PropertyManager.h"

#include "physics/Vector3D.h"

#include "rulesets/DomainProperty.h"
#include "stubs/common/stubcustom.h"
#include "stubs/rulesets/stubDomain.h"
#include "stubs/rulesets/stubDomainProperty.h"
#include "stubs/common/stubVariable.h"
#include "stubs/common/stubMonitors.h"

void addToEntity(const Point3D & p, std::vector<double> & vd)
{
    vd.resize(3);
    vd[0] = p[0];
    vd[1] = p[1];
    vd[2] = p[2];
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

#include "stubs/rulesets/stubBaseWorld.h"



#include "stubs/rulesets/stubScript.h"
#include "stubs/rulesets/stubLocation.h"
#include "stubs/rulesets/stubAtlasProperties.h"
#include "stubs/common/stubLink.h"
#include "stubs/common/stubRouter.h"


PropertyKit::~PropertyKit()
{
}

#include "stubs/common/stubPropertyManager.h"

long integerId(const std::string & id)
{
    long intId = strtol(id.c_str(), 0, 10);
    if (intId == 0 && id != "0") {
        intId = -1L;
    }

    return intId;
}

void log(LogLevel lvl, const std::string & msg)
{
}
