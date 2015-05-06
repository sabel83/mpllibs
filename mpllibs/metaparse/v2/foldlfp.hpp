#ifndef MPLLIBS_METAPARSE_V2_FOLDLFP_HPP
#define MPLLIBS_METAPARSE_V2_FOLDLFP_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/foldlf.hpp>
#include <mpllibs/metaparse/v2/get_remaining.hpp>
#include <mpllibs/metaparse/v2/get_position.hpp>
#include <mpllibs/metaparse/v2/get_result.hpp>
#include <mpllibs/metaparse/v2/is_error.hpp>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class P, class StateP, class ForwardOp>
      class foldlfp
      {
      private:
        template <class Res>
        struct apply_unchecked :
          boost::mpl::apply_wrap2<
            foldlf<P, typename get_result<Res>::type, ForwardOp>,
            typename get_remaining<Res>::type,
            typename get_position<Res>::type
          >
        {};
      public:
        typedef foldlfp type;

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
}

#endif

