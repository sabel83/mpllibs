#ifndef MPLLIBS_METAPARSE_FOLDRP_HPP
#define MPLLIBS_METAPARSE_FOLDRP_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
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
    template <class P, class StateP, class BackwardOp>
    struct foldrp
    {
    private:
      template <class Res, class Rem>
      struct apply_unchecked1 :
        boost::mpl::apply_wrap2<
          return_<
            typename boost::mpl::apply<
              BackwardOp,
              typename get_result<Res>::type,
              typename get_result<Rem>::type
            >::type
          >,
          typename get_remaining<Rem>::type,
          typename get_position<Rem>::type
        >
      {};

      template <class Res>
      struct apply_unchecked
      {
      private:
        typedef
          // I need to use apply_wrap, and not apply, because apply would
          // build a metafunction class from foldrp<P, StateP, BackwardOp>
          // when BackwardOp is a lambda expression.
          boost::mpl::apply_wrap2<
            foldrp,
            typename get_remaining<Res>::type,
            typename get_position<Res>::type
          >
          parsed_remaining;
      public:
        typedef
          typename boost::mpl::eval_if<
            typename is_error<parsed_remaining>::type,
            parsed_remaining,
            apply_unchecked1<Res, parsed_remaining>
          >::type
          type;
      };
    public:
      typedef foldrp type;
    
      template <class S, class Pos>
      struct apply :
        boost::mpl::eval_if<
          typename is_error<boost::mpl::apply<P, S, Pos> >::type,
          boost::mpl::apply<StateP, S, Pos>,
          apply_unchecked<boost::mpl::apply<P, S, Pos> >
        >
      {};
    };
  }
}

#endif

