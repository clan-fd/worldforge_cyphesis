// AUTOGENERATED file, created by the tool generate_stub.py, don't edit!
// If you want to add your own functionality, instead edit the stubConnectableRouter_custom.h file.

#include "server/ConnectableRouter.h"
#include "stubConnectableRouter_custom.h"

#ifndef STUB_SERVER_CONNECTABLEROUTER_H
#define STUB_SERVER_CONNECTABLEROUTER_H

#ifndef STUB_ConnectableRouter_ConnectableRouter
//#define STUB_ConnectableRouter_ConnectableRouter
   ConnectableRouter::ConnectableRouter(const std::string & id, long intId, Connection * c )
    : Router(id, intId, c)
    , m_connection(nullptr)
  {
    
  }
#endif //STUB_ConnectableRouter_ConnectableRouter

#ifndef STUB_ConnectableRouter_ConnectableRouter_DTOR
//#define STUB_ConnectableRouter_ConnectableRouter_DTOR
   ConnectableRouter::~ConnectableRouter()
  {
    
  }
#endif //STUB_ConnectableRouter_ConnectableRouter_DTOR


#endif