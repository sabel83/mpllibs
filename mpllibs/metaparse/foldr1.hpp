#ifndef MPLLIBS_METAPARSE_FOLDR1_HPP
#define MPLLIBS_METAPARSE_FOLDR1_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/foldr.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class State, class BackwardOp>
    struct foldr1
    {
      typedef foldr1 type;
      
      template <class S, class Pos>
      struct apply :
        boost::mpl::if_<
          is_error<boost::mpl::apply<P, S, Pos> >,
          P,
          foldr<P, State, BackwardOp>
        >::type::template apply<S, Pos>
      {};
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(3, mpllibs::metaparse::foldr1, "foldr1")

#endif

