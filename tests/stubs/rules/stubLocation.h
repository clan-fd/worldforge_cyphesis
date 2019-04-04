// AUTOGENERATED file, created by the tool generate_stub.py, don't edit!
// If you want to add your own functionality, instead edit the stubLocation_custom.h file.

#ifndef STUB_RULES_LOCATION_H
#define STUB_RULES_LOCATION_H

#include "rules/Location.h"
#include "stubLocation_custom.h"

#ifndef STUB_Location_Location
//#define STUB_Location_Location
   Location::Location()
    : EntityLocation()
  {
    
  }
#endif //STUB_Location_Location

#ifndef STUB_Location_Location
//#define STUB_Location_Location
   Location::Location(Ref<LocatedEntity> rf)
    : EntityLocation(rf)
  {
    
  }
#endif //STUB_Location_Location

#ifndef STUB_Location_Location
//#define STUB_Location_Location
   Location::Location(Ref<LocatedEntity> rf, Point3D pos)
    : EntityLocation(rf, pos)
  {
    
  }
#endif //STUB_Location_Location

#ifndef STUB_Location_Location
//#define STUB_Location_Location
   Location::Location(Ref<LocatedEntity> rf, Point3D pos, Vector3D velocity)
    : EntityLocation(rf, pos, velocity)
  {
    
  }
#endif //STUB_Location_Location

#ifndef STUB_Location_Location
//#define STUB_Location_Location
   Location::Location(LocatedEntity * rf)
    : EntityLocation(rf)
  {
    
  }
#endif //STUB_Location_Location

#ifndef STUB_Location_Location
//#define STUB_Location_Location
   Location::Location(LocatedEntity * rf, Point3D pos)
    : EntityLocation(rf, pos)
  {
    
  }
#endif //STUB_Location_Location

#ifndef STUB_Location_Location
//#define STUB_Location_Location
   Location::Location(LocatedEntity * rf, Point3D pos, Vector3D velocity)
    : EntityLocation(rf, pos, velocity)
  {
    
  }
#endif //STUB_Location_Location

#ifndef STUB_Location_Location
//#define STUB_Location_Location
   Location::Location(EntityLocation entityLocation)
    : EntityLocation(entityLocation)
  {
    
  }
#endif //STUB_Location_Location

#ifndef STUB_Location_addToMessage
//#define STUB_Location_addToMessage
  void Location::addToMessage(Atlas::Message::MapType & ent) const
  {
    
  }
#endif //STUB_Location_addToMessage

#ifndef STUB_Location_addToEntity
//#define STUB_Location_addToEntity
  void Location::addToEntity(const Atlas::Objects::Entity::RootEntity & ent) const
  {
    
  }
#endif //STUB_Location_addToEntity

#ifndef STUB_Location_asEntity
//#define STUB_Location_asEntity
  Atlas::Objects::Root Location::asEntity() const
  {
    return *static_cast<Atlas::Objects::Root*>(nullptr);
  }
#endif //STUB_Location_asEntity

#ifndef STUB_Location_readFromMessage
//#define STUB_Location_readFromMessage
  bool Location::readFromMessage(const Atlas::Message::MapType & message)
  {
    return false;
  }
#endif //STUB_Location_readFromMessage

#ifndef STUB_Location_readFromEntity
//#define STUB_Location_readFromEntity
  bool Location::readFromEntity(const Atlas::Objects::Entity::RootEntity & ent)
  {
    return false;
  }
#endif //STUB_Location_readFromEntity

#ifndef STUB_Location_modifyBBox
//#define STUB_Location_modifyBBox
  void Location::modifyBBox()
  {
    
  }
#endif //STUB_Location_modifyBBox


#endif