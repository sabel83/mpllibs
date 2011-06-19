#ifndef MPLLIBS_METAPARSE_ANY_FOLD_HPP
#define MPLLIBS_METAPARSE_ANY_FOLD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/is_error.hpp>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class State, class ForwardOp>
    struct any_fold
    {
    private:
      template <class Res>
      struct apply_unchecked
      {
      private:
        typedef
          // any_fold never returns error
          // I need to use apply_wrap, and not apply, because apply would
          // build a metafunction class from any_fold<P, State, ForwardOp>
          // when ForwardOp is a lambda expression.
          boost::mpl::apply_wrap2<
            any_fold,
            typename get_remaining<Res>::type,
            typename get_position<Res>::type
          >
          parsed_remaining;
      public:
        typedef
          boost::mpl::apply<
            return_<
              typename boost::mpl::apply<
                ForwardOp,
                typename get_result<parsed_remaining>::type,
                typename get_result<Res>::type
              >::type
            >,
            typename get_remaining<parsed_remaining>::type,
            typename get_position<parsed_remaining>::type
          >
          type;
      };
    public:
      template <class S, class Pos>
      struct apply :
        boost::mpl::eval_if<
          typename is_error<boost::mpl::apply<P, S, Pos> >::type,
          boost::mpl::apply<return_<State>, S, Pos>,
          apply_unchecked<boost::mpl::apply<P, S, Pos> >
        >
      {};
    };
  }
}

#endif

