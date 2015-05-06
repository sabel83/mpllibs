#ifndef MPLLIBS_METAPARSE_V2_FOLDLF1_HPP
#define MPLLIBS_METAPARSE_V2_FOLDLF1_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/foldlf.hpp>

#include <boost/mpl/if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class P, class State, class ForwardOp>
      struct foldlf1
      {
        typedef foldlf1 type;
      
        template <class S, class Pos>
        struct apply :
          boost::mpl::if_<
            is_error<boost::mpl::apply<P, S, Pos> >,
            P,
            foldlf<P, State, ForwardOp>
          >::type::template apply<S, Pos>
        {};
      };
    }
  }
}

#endif

