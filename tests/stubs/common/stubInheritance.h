// AUTOGENERATED file, created by the tool generate_stub.py, don't edit!
// If you want to add your own functionality, instead edit the stubInheritance_custom.h file.

#ifndef STUB_COMMON_INHERITANCE_H
#define STUB_COMMON_INHERITANCE_H

#include "common/Inheritance.h"
#include "stubInheritance_custom.h"

#ifndef STUB_Inheritance_Inheritance
//#define STUB_Inheritance_Inheritance
   Inheritance::Inheritance()
    : Singleton()
  {
    
  }
#endif //STUB_Inheritance_Inheritance

#ifndef STUB_Inheritance_Inheritance_DTOR
//#define STUB_Inheritance_Inheritance_DTOR
   Inheritance::~Inheritance()
  {
    
  }
#endif //STUB_Inheritance_Inheritance_DTOR

#ifndef STUB_Inheritance_getClass
//#define STUB_Inheritance_getClass
  const Atlas::Objects::Root& Inheritance::getClass(const std::string & parent, Visibility visibility)
  {
    return *static_cast<const Atlas::Objects::Root*>(nullptr);
  }
#endif //STUB_Inheritance_getClass

#ifndef STUB_Inheritance_updateClass
//#define STUB_Inheritance_updateClass
  int Inheritance::updateClass(const std::string & name, const Atlas::Objects::Root & obj)
  {
    return 0;
  }
#endif //STUB_Inheritance_updateClass

#ifndef STUB_Inheritance_getType
//#define STUB_Inheritance_getType
  const TypeNode* Inheritance::getType(const std::string & parent) const
  {
    return nullptr;
  }
#endif //STUB_Inheritance_getType

#ifndef STUB_Inheritance_hasClass
//#define STUB_Inheritance_hasClass
  bool Inheritance::hasClass(const std::string & parent)
  {
    return false;
  }
#endif //STUB_Inheritance_hasClass

#ifndef STUB_Inheritance_addChild
//#define STUB_Inheritance_addChild
  TypeNode* Inheritance::addChild(const Atlas::Objects::Root & obj)
  {
    return nullptr;
  }
#endif //STUB_Inheritance_addChild

#ifndef STUB_Inheritance_isTypeOf
//#define STUB_Inheritance_isTypeOf
  bool Inheritance::isTypeOf(const std::string & instance, const std::string & base_type) const
  {
    return false;
  }
#endif //STUB_Inheritance_isTypeOf

#ifndef STUB_Inheritance_isTypeOf
//#define STUB_Inheritance_isTypeOf
  bool Inheritance::isTypeOf(const TypeNode * instance, const std::string & base_type) const
  {
    return false;
  }
#endif //STUB_Inheritance_isTypeOf

#ifndef STUB_Inheritance_isTypeOf
//#define STUB_Inheritance_isTypeOf
  bool Inheritance::isTypeOf(const TypeNode * instance, const TypeNode * base_type) const
  {
    return false;
  }
#endif //STUB_Inheritance_isTypeOf

#ifndef STUB_Inheritance_flush
//#define STUB_Inheritance_flush
  void Inheritance::flush()
  {
    
  }
#endif //STUB_Inheritance_flush


#endif