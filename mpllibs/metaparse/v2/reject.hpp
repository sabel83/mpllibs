#ifndef MPLLIBS_METAPARSE_V2_REJECT_HPP
#define MPLLIBS_METAPARSE_V2_REJECT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/fwd/reject.hpp>
#include <mpllibs/metaparse/v2/impl/eval_if_possible.hpp>
#include <mpllibs/metaparse/v2/fail_tag.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class Msg, class Pos>
      struct reject
      {
        typedef fail_tag tag;

        typedef
          reject<
            typename impl::eval_if_possible<Msg>::type,
            typename Pos::type
          >
          type;
        
        typedef Pos source_position;
        typedef Msg message;
      };
    }
  }
}

#endif

