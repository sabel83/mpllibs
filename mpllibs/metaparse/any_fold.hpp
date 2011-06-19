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

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class State, class ForwardOp>
    struct any_fold
    {
    private:
      template <class Res>
      struct apply_unchecked :
        boost::mpl::apply<
          return_<
            typename boost::mpl::apply<
              ForwardOp,
              typename get_result<
                // any_fold never returns error
                boost::mpl::apply<
                  any_fold,
                  typename get_remaining<Res>::type,
                  typename get_position<Res>::type
                >
              >::type,
              typename get_result<Res>::type
            >::type
          >,
          typename get_remaining<
            // any_fold never returns error
            boost::mpl::apply<
              any_fold,
              typename get_remaining<Res>::type,
              typename get_position<Res>::type
            >
          >::type,
          typename mpllibs::metaparse::get_position<
            // any_fold never returns error
            boost::mpl::apply<
              any_fold,
              typename get_remaining<Res>::type,
              typename get_position<Res>::type
            >
          >::type
        >
      {};
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

