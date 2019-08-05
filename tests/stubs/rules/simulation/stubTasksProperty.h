// AUTOGENERATED file, created by the tool generate_stub.py, don't edit!
// If you want to add your own functionality, instead edit the stubTasksProperty_custom.h file.

#ifndef STUB_RULES_SIMULATION_TASKSPROPERTY_H
#define STUB_RULES_SIMULATION_TASKSPROPERTY_H

#include "rules/simulation/TasksProperty.h"
#include "stubTasksProperty_custom.h"

#ifndef STUB_TasksProperty_TasksProperty
//#define STUB_TasksProperty_TasksProperty
   TasksProperty::TasksProperty()
    : PropertyBase()
  {
    
  }
#endif //STUB_TasksProperty_TasksProperty

#ifndef STUB_TasksProperty_install
//#define STUB_TasksProperty_install
  void TasksProperty::install(LocatedEntity*, const std::string&)
  {
    
  }
#endif //STUB_TasksProperty_install

#ifndef STUB_TasksProperty_remove
//#define STUB_TasksProperty_remove
  void TasksProperty::remove(LocatedEntity*, const std::string& name)
  {
    
  }
#endif //STUB_TasksProperty_remove

#ifndef STUB_TasksProperty_get
//#define STUB_TasksProperty_get
  int TasksProperty::get(Atlas::Message::Element& val) const
  {
    return 0;
  }
#endif //STUB_TasksProperty_get

#ifndef STUB_TasksProperty_set
//#define STUB_TasksProperty_set
  void TasksProperty::set(const Atlas::Message::Element& val)
  {
    
  }
#endif //STUB_TasksProperty_set

#ifndef STUB_TasksProperty_copy
//#define STUB_TasksProperty_copy
  TasksProperty* TasksProperty::copy() const
  {
    return nullptr;
  }
#endif //STUB_TasksProperty_copy

#ifndef STUB_TasksProperty_updateTask
//#define STUB_TasksProperty_updateTask
  int TasksProperty::updateTask(LocatedEntity* owner, OpVector& res)
  {
    return 0;
  }
#endif //STUB_TasksProperty_updateTask

#ifndef STUB_TasksProperty_startTask
//#define STUB_TasksProperty_startTask
  int TasksProperty::startTask(const std::string& id, Ref<Task> task, LocatedEntity* owner, OpVector& res)
  {
    return 0;
  }
#endif //STUB_TasksProperty_startTask

#ifndef STUB_TasksProperty_clearTask
//#define STUB_TasksProperty_clearTask
  int TasksProperty::clearTask(const std::string& id, LocatedEntity* owner, OpVector& res)
  {
    return 0;
  }
#endif //STUB_TasksProperty_clearTask

#ifndef STUB_TasksProperty_stopTask
//#define STUB_TasksProperty_stopTask
  void TasksProperty::stopTask(const std::string& id, LocatedEntity* owner, OpVector& res)
  {
    
  }
#endif //STUB_TasksProperty_stopTask

#ifndef STUB_TasksProperty_TickOperation
//#define STUB_TasksProperty_TickOperation
  void TasksProperty::TickOperation(LocatedEntity* owner, const Operation& op, OpVector&)
  {
    
  }
#endif //STUB_TasksProperty_TickOperation

#ifndef STUB_TasksProperty_UseOperation
//#define STUB_TasksProperty_UseOperation
  void TasksProperty::UseOperation(LocatedEntity* owner, const Operation& op, OpVector&)
  {
    
  }
#endif //STUB_TasksProperty_UseOperation

#ifndef STUB_TasksProperty_operation
//#define STUB_TasksProperty_operation
  HandlerResult TasksProperty::operation(LocatedEntity* owner, const Operation& op, OpVector&)
  {
    return *static_cast<HandlerResult*>(nullptr);
  }
#endif //STUB_TasksProperty_operation


#endif