// AUTOGENERATED file, created by the tool generate_stub.py, don't edit!
// If you want to add your own functionality, instead edit the stubInventoryDomain_custom.h file.

#ifndef STUB_RULES_SIMULATION_INVENTORYDOMAIN_H
#define STUB_RULES_SIMULATION_INVENTORYDOMAIN_H

#include "rules/simulation/InventoryDomain.h"
#include "stubInventoryDomain_custom.h"

#ifndef STUB_InventoryDomain_InventoryDomain
//#define STUB_InventoryDomain_InventoryDomain
   InventoryDomain::InventoryDomain(LocatedEntity& entity)
    : Domain(entity)
  {
    
  }
#endif //STUB_InventoryDomain_InventoryDomain

#ifndef STUB_InventoryDomain_isEntityVisibleFor
//#define STUB_InventoryDomain_isEntityVisibleFor
  bool InventoryDomain::isEntityVisibleFor(const LocatedEntity& observingEntity, const LocatedEntity& observedEntity) const
  {
    return false;
  }
#endif //STUB_InventoryDomain_isEntityVisibleFor

#ifndef STUB_InventoryDomain_getVisibleEntitiesFor
//#define STUB_InventoryDomain_getVisibleEntitiesFor
  void InventoryDomain::getVisibleEntitiesFor(const LocatedEntity& observingEntity, std::list<LocatedEntity*>& entityList) const
  {
    
  }
#endif //STUB_InventoryDomain_getVisibleEntitiesFor

#ifndef STUB_InventoryDomain_getObservingEntitiesFor
//#define STUB_InventoryDomain_getObservingEntitiesFor
  std::vector<LocatedEntity*> InventoryDomain::getObservingEntitiesFor(const LocatedEntity& observedEntity) const
  {
    return std::vector<LocatedEntity*>();
  }
#endif //STUB_InventoryDomain_getObservingEntitiesFor

#ifndef STUB_InventoryDomain_addEntity
//#define STUB_InventoryDomain_addEntity
  void InventoryDomain::addEntity(LocatedEntity& entity)
  {
    
  }
#endif //STUB_InventoryDomain_addEntity

#ifndef STUB_InventoryDomain_removeEntity
//#define STUB_InventoryDomain_removeEntity
  void InventoryDomain::removeEntity(LocatedEntity& entity)
  {
    
  }
#endif //STUB_InventoryDomain_removeEntity

#ifndef STUB_InventoryDomain_isEntityReachable
//#define STUB_InventoryDomain_isEntityReachable
  bool InventoryDomain::isEntityReachable(const LocatedEntity& reachingEntity, float reach, const LocatedEntity& queriedEntity, const WFMath::Point<3>& positionOnQueriedEntity) const
  {
    return false;
  }
#endif //STUB_InventoryDomain_isEntityReachable

#ifndef STUB_InventoryDomain_queryCollision
//#define STUB_InventoryDomain_queryCollision
  std::vector<Domain::CollisionEntry> InventoryDomain::queryCollision(const WFMath::Ball<3>& sphere) const
  {
    return std::vector<Domain::CollisionEntry>();
  }
#endif //STUB_InventoryDomain_queryCollision

#ifndef STUB_InventoryDomain_observeCloseness
//#define STUB_InventoryDomain_observeCloseness
  boost::optional<std::function<()>> InventoryDomain::observeCloseness(LocatedEntity& reacher, LocatedEntity& target, double reach, std::function<void()> callback)
  {
    return *static_cast<boost::optional<std::function<()>>*>(nullptr);
  }
#endif //STUB_InventoryDomain_observeCloseness


#endif