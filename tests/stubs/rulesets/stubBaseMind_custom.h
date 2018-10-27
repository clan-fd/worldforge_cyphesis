//Add custom implementations of stubbed functions here; this file won't be rewritten when re-generating stubs.
#include "rulesets/SimpleTypeStore.h"
#include "rulesets/TypeResolver.h"
#include "rulesets/Script.h"

#ifndef STUB_BaseMind_BaseMind
#define STUB_BaseMind_BaseMind
BaseMind::BaseMind(const std::string & mindId, const std::string & entityId)
    : Router(mindId, std::stol(mindId)),
      m_flags(0),
      m_typeResolver(nullptr),
      m_map(*m_typeResolver)
{

}
#endif //STUB_BaseMind_BaseMind
