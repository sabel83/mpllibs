#ifndef MPLLIBS_METAPARSE_FOLDLP_HPP
#define MPLLIBS_METAPARSE_FOLDLP_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/foldl.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class StateP, class ForwardOp>
    class foldlp
    {
    private:
      template <class Res>
      struct apply_unchecked :
        boost::mpl::apply_wrap2<
          foldl<P, typename get_result<Res>::type, ForwardOp>,
          typename get_remaining<Res>::type,
          typename get_position<Res>::type
        >
      {};
    public:
      typedef foldlp type;

      template <class S, class Pos>
      struct apply :
        boost::mpl::eval_if<
          typename is_error<boost::mpl::apply<StateP, S, Pos> >::type,
          boost::mpl::apply<StateP, S, Pos>,
          apply_unchecked<boost::mpl::apply<StateP, S, Pos> >
        >
      {};
    };
  }
}

#endif

