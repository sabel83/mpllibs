#ifndef MPLLIBS_METAPARSE_V2_FOLDL_HPP
#define MPLLIBS_METAPARSE_V2_FOLDL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/accept.hpp>
#include <mpllibs/metaparse/v2/is_error.hpp>
#include <mpllibs/metaparse/v2/get_position.hpp>
#include <mpllibs/metaparse/v2/get_result.hpp>
#include <mpllibs/metaparse/v2/get_remaining.hpp>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class P, class State, class ForwardOp>
      struct foldl
      {
      private:
        template <class Res>
        struct apply_unchecked :
          // foldl never returns error
          // I need to use apply_wrap, and not apply, because apply would
          // build a metafunction class from foldl<P, State, ForwardOp>
          // when ForwardOp is a lambda expression.
          boost::mpl::apply_wrap2<
            foldl<
              P,
              boost::mpl::apply<
                ForwardOp,
                typename State::type,
                typename get_result<Res>::type
              >,
              ForwardOp
            >,
            typename get_remaining<Res>::type,
            typename get_position<Res>::type
          >
        {};
      public:
        typedef foldl type;
      
        template <class S, class Pos>
        struct apply :
          boost::mpl::eval_if<
            typename is_error<boost::mpl::apply<P, S, Pos> >::type,
            accept<State, S, Pos>,
            apply_unchecked<boost::mpl::apply<P, S, Pos> >
          >
        {};
      };
    }
  }
}

#endif

