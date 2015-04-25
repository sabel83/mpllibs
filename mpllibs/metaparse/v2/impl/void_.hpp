#ifndef MPLLIBS_METAPARSE_V2_IMPL_VOID_HPP
#define MPLLIBS_METAPARSE_V2_IMPL_VOID_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_tag.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace impl
      {
        struct void_ : metamonad::tmp_tag<void_> {};
      }
    }
  }
}

#endif

