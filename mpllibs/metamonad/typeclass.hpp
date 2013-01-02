#ifndef MPLLIBS_METAMONAD_TYPECLASS_HPP
#define MPLLIBS_METAMONAD_TYPECLASS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/exception_core.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct invalid_typeclass_tag : tmp_tag<invalid_typeclass_tag> {};

    struct invalid_typeclass :
      tmp_value<invalid_typeclass, invalid_typeclass_tag>
    {};
    
    #ifdef MPLLIBS_TYPECLASS_EXPECT
      #error MPLLIBS_TYPECLASS_EXPECT already defined
    #endif
    #define MPLLIBS_TYPECLASS_EXPECT(name) \
      typedef \
        mpllibs::metamonad::exception<mpllibs::metamonad::invalid_typeclass> \
        name
  
    struct typeclass_expectations : tmp_tag<typeclass_expectations> {};
  }
}

#endif

