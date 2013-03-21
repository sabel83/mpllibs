#ifndef MPLLIBS_METAPARSE_FAIL_HPP
#define MPLLIBS_METAPARSE_FAIL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/fail_tag.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class Msg>
    struct fail
    {
      typedef fail type;
      
      template <class S, class Pos>
      struct apply
      {
        typedef fail_tag tag;
        typedef apply type;

        typedef Pos source_position;
        typedef Msg message;
      };
    };
  }
}

#endif

