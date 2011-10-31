// Cyphesis Online RPG Server and AI Engine
// Copyright (C) 2005 Alistair Riddoch
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

// $Id$

#ifndef TESTS_TEST_WORLD_H
#define TESTS_TEST_WORLD_H

#include "common/BaseWorld.h"

#include "rulesets/Entity.h"

/// Test implementation of the BaseWorld interface
class TestWorld : public BaseWorld {
  public:
    explicit TestWorld(Entity & gw) : BaseWorld(gw) {
        m_eobjects[m_gameWorld.getIntId()] = &m_gameWorld;
    }

    virtual bool idle(const SystemTime &) { return false; }
    virtual Entity * addEntity(Entity * ent) { 
        m_eobjects[ent->getIntId()] = ent;
        return 0;
    }
    virtual Entity * addNewEntity(const std::string &,
                                  const Atlas::Objects::Entity::RootEntity &) {
        return 0;
    }
    int createSpawnPoint(const Atlas::Message::MapType & data,
                         Entity *) { return 0; }
    int getSpawnList(Atlas::Message::ListType & data) { return 0; }
    Entity * spawnNewEntity(const std::string & name,
                            const std::string & type,
                            const Atlas::Objects::Entity::RootEntity & desc) {
        return addNewEntity(type, desc);
    }
    virtual Task * newTask(const std::string &, Character &) { return 0; }
    virtual Task * activateTask(const std::string &, const std::string &,
                                const std::string &, Character &) { return 0; }
    virtual ArithmeticScript * newArithmetic(const std::string &, Entity *) {
        return 0;
    }
    virtual void message(const Operation & op, Entity & ent) { }
    virtual Entity * findByName(const std::string & name) { return 0; }
    virtual Entity * findByType(const std::string & type) { return 0; }
    virtual void addPerceptive(Entity *) { }
};

#endif // TESTS_TEST_WORLD_H
