#ifndef MPLLIBS_METAMONAD_V1_INVALID_TYPECLASS_HPP
#define MPLLIBS_METAMONAD_V1_INVALID_TYPECLASS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/invalid_typeclass.hpp>
#include <mpllibs/metamonad/v1/invalid_typeclass_tag.hpp>
#include <mpllibs/metamonad/v1/tmp_value.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      struct invalid_typeclass :
        tmp_value<invalid_typeclass, invalid_typeclass_tag>
      {};
    }
  }
}

#endif

