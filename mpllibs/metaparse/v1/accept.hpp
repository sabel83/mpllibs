#ifndef MPLLIBS_METAPARSE_V1_ACCEPT_HPP
#define MPLLIBS_METAPARSE_V1_ACCEPT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/fwd/accept.hpp>
#include <mpllibs/metaparse/v1/accept_tag.hpp>
#include <mpllibs/metaparse/v1/impl/eval_if_possible.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      template <class Result, class Remaining, class Pos>
      struct accept
      {
        typedef accept_tag tag;

        typedef
          accept<
            typename impl::eval_if_possible<Result>::type,
            typename Remaining::type,
            typename Pos::type
          >
          type;

        typedef Result result;
        typedef Remaining remaining;
        typedef Pos source_position;
      };
    }
  }
}

#endif

