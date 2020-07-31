// AUTOGENERATED file, created by the tool generate_stub.py, don't edit!
// If you want to add your own functionality, instead edit the stubServerRouting_custom.h file.

#ifndef STUB_SERVER_SERVERROUTING_H
#define STUB_SERVER_SERVERROUTING_H

#include "server/ServerRouting.h"
#include "stubServerRouting_custom.h"

#ifndef STUB_ServerRouting_ServerRouting
//#define STUB_ServerRouting_ServerRouting
   ServerRouting::ServerRouting(BaseWorld& wrld, std::string ruleset, std::string name, const std::string& id, long intId, const std::string& lId, long lIntId)
    : Router(wrld, ruleset, name, id, intId, lId, lIntId)
  {
    
  }
#endif //STUB_ServerRouting_ServerRouting

#ifndef STUB_ServerRouting_ServerRouting_DTOR
//#define STUB_ServerRouting_ServerRouting_DTOR
   ServerRouting::~ServerRouting()
  {
    
  }
#endif //STUB_ServerRouting_ServerRouting_DTOR

#ifndef STUB_ServerRouting_disconnectAllConnections
//#define STUB_ServerRouting_disconnectAllConnections
  void ServerRouting::disconnectAllConnections()
  {
    
  }
#endif //STUB_ServerRouting_disconnectAllConnections

#ifndef STUB_ServerRouting_addObject
//#define STUB_ServerRouting_addObject
  void ServerRouting::addObject(std::unique_ptr<ConnectableRouter> obj)
  {
    
  }
#endif //STUB_ServerRouting_addObject

#ifndef STUB_ServerRouting_addAccount
//#define STUB_ServerRouting_addAccount
  void ServerRouting::addAccount(std::unique_ptr<Account> a)
  {
    
  }
#endif //STUB_ServerRouting_addAccount

#ifndef STUB_ServerRouting_delObject
//#define STUB_ServerRouting_delObject
  void ServerRouting::delObject(ConnectableRouter* obj)
  {
    
  }
#endif //STUB_ServerRouting_delObject

#ifndef STUB_ServerRouting_getObject
//#define STUB_ServerRouting_getObject
  ConnectableRouter* ServerRouting::getObject(const std::string& id) const
  {
    return nullptr;
  }
#endif //STUB_ServerRouting_getObject

#ifndef STUB_ServerRouting_getAccountByName
//#define STUB_ServerRouting_getAccountByName
  Account* ServerRouting::getAccountByName(const std::string& username)
  {
    return nullptr;
  }
#endif //STUB_ServerRouting_getAccountByName

#ifndef STUB_ServerRouting_addToMessage
//#define STUB_ServerRouting_addToMessage
  void ServerRouting::addToMessage(Atlas::Message::MapType&) const
  {
    
  }
#endif //STUB_ServerRouting_addToMessage

#ifndef STUB_ServerRouting_addToEntity
//#define STUB_ServerRouting_addToEntity
  void ServerRouting::addToEntity(const Atlas::Objects::Entity::RootEntity&) const
  {
    
  }
#endif //STUB_ServerRouting_addToEntity

#ifndef STUB_ServerRouting_externalOperation
//#define STUB_ServerRouting_externalOperation
  void ServerRouting::externalOperation(const Operation& op, Link&)
  {
    
  }
#endif //STUB_ServerRouting_externalOperation

#ifndef STUB_ServerRouting_operation
//#define STUB_ServerRouting_operation
  void ServerRouting::operation(const Operation&, OpVector&)
  {
    
  }
#endif //STUB_ServerRouting_operation

#ifndef STUB_ServerRouting_dispatch
//#define STUB_ServerRouting_dispatch
  size_t ServerRouting::dispatch(size_t numberOfOps)
  {
    return 0;
  }
#endif //STUB_ServerRouting_dispatch


#endif