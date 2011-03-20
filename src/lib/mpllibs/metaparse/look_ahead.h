#ifndef MPLLIBS_PARSER_LOOK_AHEAD_H
#define MPLLIBS_PARSER_LOOK_AHEAD_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)   2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/return.h>
#include <mpllibs/metaparse/get_result.h>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p>
    struct look_ahead
    {
      template <class s, class pos>
      struct apply :
        boost::mpl::eval_if<
          typename mpllibs::metaparse::is_error<
            boost::mpl::apply<p, s, pos>
          >::type,
          boost::mpl::apply<p, s, pos>,
          boost::mpl::apply<
            mpllibs::metaparse::return_<
              mpllibs::metaparse::get_result<boost::mpl::apply<p, s, pos> >
            >,
            s,
            pos
          >
        >
      {};
    };
  }
}

#endif

