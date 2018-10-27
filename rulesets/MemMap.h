// Cyphesis Online RPG Server and AI Engine
// Copyright (C) 2000,2001 Alistair Riddoch
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


#ifndef RULESETS_MEM_MAP_H
#define RULESETS_MEM_MAP_H

#include "common/OperationRouter.h"

#include "MemEntity.h"
#include "modules/Ref.h"

#include <Atlas/Objects/ObjectsFwd.h>
#include <Atlas/Message/Element.h>

#include <wfmath/const.h>

#include <list>
#include <map>
#include <string>
#include <boost/optional.hpp>
#include <common/TypeStore.h>

class LocatedEntity;
class Location;
class Script;
class TypeNode;
class TypeResolver;

typedef std::vector<LocatedEntity *> EntityVector;

/// \brief Class to handle the basic entity memory of a mind
class MemMap {
  public:
    struct MapListener {
        virtual ~MapListener() = default;

        virtual void entityAdded(const MemEntity& entity) = 0;
        virtual void entityUpdated(const MemEntity& entity, const Atlas::Objects::Entity::RootEntity & ent, LocatedEntity* oldLocation) = 0;
        virtual void entityDeleted(const MemEntity& entity) = 0;
    };

  protected:
    friend class BaseMind;

    typedef std::map<long, Ref<MemEntity>> MemEntityDict;

    std::map<std::string, std::set<Ref<MemEntity>>> m_unresolvedEntities;

    MemEntityDict m_entities;

    MemEntityDict::iterator m_checkIterator;
    std::list<std::string> m_additionsById;
    std::vector<std::string> m_addHooks;
    std::vector<std::string> m_updateHooks;
    std::vector<std::string> m_deleteHooks;
    Script* m_script;

    MapListener* m_listener;

    TypeResolver& m_typeResolver;

    ///\brief a map that holds memories related to other entities.
    ///@key - ID of the entity to which we relate memories
    ///@value - Element of map type containing name of a memory as a key
    ///and the value of that memory (i.e. disposition: 25)
    std::map<std::string, std::map<std::string, Atlas::Message::Element>> m_entityRelatedMemory;

    OpVector m_typeResolverOps;

    void readEntity(const Ref<MemEntity>&, const Atlas::Objects::Entity::RootEntity &, double timestamp);
    void updateEntity(const Ref<MemEntity>&, const Atlas::Objects::Entity::RootEntity &, double timestamp);
    Ref<MemEntity> newEntity(const std::string &, long,
                          const Atlas::Objects::Entity::RootEntity &, double timestamp);
    void addContents(const Atlas::Objects::Entity::RootEntity &);
    Ref<MemEntity> addId(const std::string &, long);

  public:

    explicit MemMap(TypeResolver& typeResolver);

    std::vector<Ref<MemEntity>> resolveEntitiesForType(const TypeNode* typeNode);

    Ref<MemEntity> addEntity(const Ref<MemEntity>&);
    void setScript(Script* script);

    bool find(const std::string & id) const;

    bool find(long id) const {
        return (m_entities.find(id) != m_entities.end());
    }

    const MemEntityDict & getEntities() const {
        return m_entities;
    }

    void sendLooks(OpVector &);
    void del(const std::string & id);
    Ref<MemEntity> get(const std::string & id) const;
    Ref<MemEntity> getAdd(const std::string & id);
    Ref<MemEntity> updateAdd(const Atlas::Objects::Entity::RootEntity &, const double &);

    ///\brief Add an entity-related memory or update it if it already exists
    ///@param id - the id of entity to which we relate the memory
    ///@param memory - the name of the memory (i.e. "disposition")
    ///@param val - value of the memory in Element (i.e. 25)
    void addEntityMemory(const std::string& id,
                             const std::string& memory,
                             const Atlas::Message::Element& value);

    ///\brief Recall a memory about an entity if it exists. Do nothing otherwise.
    ///@param id - the id of entity to which we relate the memory
    ///@param memory - the name of the memory (i.e. "disposition")
    ///@param val - the Element to record the value in.
    void recallEntityMemory(const std::string& id,
                                const std::string& memory,
                                Atlas::Message::Element& value) const;

    ///\brief m_entityRelatedMemory accessor
    const std::map<std::string, std::map<std::string, Atlas::Message::Element>>& getEntityRelatedMemory() const;

    EntityVector findByType(const std::string & what);
    EntityVector findByLocation(const EntityLocation & where,
                                WFMath::CoordType radius,
                                const std::string & what);

    void check(const double &);
    void flush();

    std::vector<std::string> & getAddHooks() { return m_addHooks; }
    std::vector<std::string> & getUpdateHooks() { return m_updateHooks; }
    std::vector<std::string> & getDeleteHooks() { return m_deleteHooks; }

    void setListener(MapListener* listener);

    void collectTypeResolverOps(OpVector& res);

    const TypeStore& getTypeStore() const;

    friend class MemMaptest;
    friend class BaseMindMapEntityintegration;
};

#endif // RULESETS_MEM_MAP_H
