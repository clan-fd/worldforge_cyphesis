// AUTOGENERATED file, created by the tool generate_stub.py, don't edit!
// If you want to add your own functionality, instead edit the stubAwarenessStore_custom.h file.

#ifndef STUB_RULES_AI_AWARENESSSTORE_H
#define STUB_RULES_AI_AWARENESSSTORE_H

#include "rules/ai/AwarenessStore.h"
#include "stubAwarenessStore_custom.h"

#ifndef STUB_AwarenessStore_AwarenessStore
//#define STUB_AwarenessStore_AwarenessStore
   AwarenessStore::AwarenessStore(float agentRadius, float agentHeight, float stepHeight, IHeightProvider& heightProvider, int tileSize )
  {
    
  }
#endif //STUB_AwarenessStore_AwarenessStore

#ifndef STUB_AwarenessStore_requestAwareness
//#define STUB_AwarenessStore_requestAwareness
  std::shared_ptr<Awareness> AwarenessStore::requestAwareness(const LocatedEntity& domainEntity)
  {
    return *static_cast<std::shared_ptr<Awareness>*>(nullptr);
  }
#endif //STUB_AwarenessStore_requestAwareness


#endif