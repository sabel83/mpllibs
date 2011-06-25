#ifndef MPLLIBS_METAPARSE_LOOK_AHEAD_HPP
#define MPLLIBS_METAPARSE_LOOK_AHEAD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)   2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P>
    struct look_ahead
    {
      typedef look_ahead type;
      
      template <class S, class Pos>
      struct apply :
        boost::mpl::eval_if<
          typename is_error<boost::mpl::apply<P, S, Pos> >::type,
          boost::mpl::apply<P, S, Pos>,
          boost::mpl::apply_wrap2<
            return_<get_result<boost::mpl::apply<P, S, Pos> > >,
            S,
            Pos
          >
        >
      {};
    };
  }
}

#endif

