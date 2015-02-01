#ifndef MPLLIBS_METAPARSE_V2_FAIL_HPP
#define MPLLIBS_METAPARSE_V2_FAIL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/reject.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class Msg>
      struct fail
      {
        typedef fail type;
        
        template <class S, class Pos>
        struct apply : reject<Msg, Pos> {};
      };
    }
  }
}

#endif

