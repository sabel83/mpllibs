#ifndef MPLLIBS_METAMONAD_TYPECLASS_HPP
#define MPLLIBS_METAMONAD_TYPECLASS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tag_tag.hpp>
#include <mpllibs/metamonad/meta_atom.hpp>
#include <mpllibs/metamonad/throw.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_DEFINE_TAG(invalid_typeclass_tag)
    MPLLIBS_DEFINE_META_ATOM(invalid_typeclass_tag, invalid_typeclass)
    
    #ifdef MPLLIBS_TYPECLASS_EXPECT
      #error MPLLIBS_TYPECLASS_EXPECT already defined
    #endif
    #define MPLLIBS_TYPECLASS_EXPECT(name) \
      typedef \
        mpllibs::metamonad::throw_<mpllibs::metamonad::invalid_typeclass> name;
  
    MPLLIBS_DEFINE_TAG(typeclass_expectations)
  }
}

#endif

