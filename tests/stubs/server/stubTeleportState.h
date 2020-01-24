// AUTOGENERATED file, created by the tool generate_stub.py, don't edit!
// If you want to add your own functionality, instead edit the stubTeleportState_custom.h file.

#ifndef STUB_SERVER_TELEPORTSTATE_H
#define STUB_SERVER_TELEPORTSTATE_H

#include "server/TeleportState.h"
#include "stubTeleportState_custom.h"

#ifndef STUB_TeleportState_TeleportState
//#define STUB_TeleportState_TeleportState
   TeleportState::TeleportState(std::chrono::steady_clock::time_point time)
  {
    
  }
#endif //STUB_TeleportState_TeleportState

#ifndef STUB_TeleportState_setRequested
//#define STUB_TeleportState_setRequested
  void TeleportState::setRequested()
  {
    
  }
#endif //STUB_TeleportState_setRequested

#ifndef STUB_TeleportState_setCreated
//#define STUB_TeleportState_setCreated
  void TeleportState::setCreated()
  {
    
  }
#endif //STUB_TeleportState_setCreated

#ifndef STUB_TeleportState_setKey
//#define STUB_TeleportState_setKey
  void TeleportState::setKey(const std::string & key)
  {
    
  }
#endif //STUB_TeleportState_setKey

#ifndef STUB_TeleportState_isCreated
//#define STUB_TeleportState_isCreated
  bool TeleportState::isCreated() const
  {
    return false;
  }
#endif //STUB_TeleportState_isCreated

#ifndef STUB_TeleportState_isRequested
//#define STUB_TeleportState_isRequested
  bool TeleportState::isRequested() const
  {
    return false;
  }
#endif //STUB_TeleportState_isRequested

#ifndef STUB_TeleportState_isMind
//#define STUB_TeleportState_isMind
  bool TeleportState::isMind() const
  {
    return false;
  }
#endif //STUB_TeleportState_isMind

#ifndef STUB_TeleportState_getPossessKey
//#define STUB_TeleportState_getPossessKey
  const std::string& TeleportState::getPossessKey() const
  {
    static std::string instance; return instance;
  }
#endif //STUB_TeleportState_getPossessKey

#ifndef STUB_TeleportState_getCreateTime
//#define STUB_TeleportState_getCreateTime
  std::chrono::steady_clock::time_point TeleportState::getCreateTime() const
  {
    return *static_cast<std::chrono::steady_clock::time_point*>(nullptr);
  }
#endif //STUB_TeleportState_getCreateTime


#endif