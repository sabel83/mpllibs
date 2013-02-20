#ifndef MPLLIBS_METAMONAD_TRY_HPP
#define MPLLIBS_METAMONAD_TRY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/make_monadic.hpp>
#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/eval_let.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/var.hpp>
#include <mpllibs/metamonad/if.hpp>
#include <mpllibs/metamonad/second.hpp>
#include <mpllibs/metamonad/pair.hpp>

#include <boost/mpl/fold.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/bool.hpp>

#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct try_a_;
    struct try_e_;
    struct try_s_;

    typedef var<try_a_> try_a;
    typedef var<try_e_> try_e;
    typedef var<try_s_> try_s;

    template <class Name, class Pred, class Body>
    struct catch_ : tmp_value<catch_<Name, Pred, Body> > {};

    template <class Name, class Pred, class Body>
    struct catch_c : tmp_value<catch_c<Name, Pred, Body> > {};

    namespace impl
    {
      template <class E, class N, class Pred, class Body>
      struct handle_catch_impl :
        if_<
          eval_let<N, syntax<E>, Pred>,
          pair<boost::mpl::false_, eval_let<N, syntax<E>, Body> >,
          pair<boost::mpl::true_, exception<E> >
        >
      {};

      template <class E, class Catch>
      struct handle_catch;

      template <class E, class N, class Pred, class Body>
      struct handle_catch<E, catch_c<N, Pred, Body> > :
        handle_catch_impl<
          typename E::type,
          typename N::type,
          syntax<Pred>,
          syntax<Body>
        >
      {};

      template <class E, class N, class Pred, class Body>
      struct handle_catch<E, catch_<N, Pred, Body> > :
        handle_catch_impl<
          typename E::type,
          typename N::type,
          typename Pred::type,
          typename Body::type
        >
      {};
    }

    template <
      class Expr, 
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        BOOST_MPL_LIMIT_METAFUNCTION_ARITY,
        class Catch,
        boost::mpl::na
      )
    >
    struct try_ :
      eval_case<
        make_monadic<exception_tag, Expr>,
        matches_c<
          exception<try_e>,
          second<
            boost::mpl::fold<
              boost::mpl::vector<
                BOOST_PP_ENUM_PARAMS(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, Catch)
              >,
              pair<boost::mpl::true_, exception<try_e> >,
              lambda_c<try_s, try_a,
                eval_case<
                  try_s,
                  matches_c<
                    pair<boost::mpl::true_, _>,
                    impl::handle_catch<try_e, try_a>
                  >,
                  matches_c<pair<boost::mpl::false_, _>, try_s>
                >
              >
            >
          >
        >,
        matches_c<_, make_monadic<exception_tag, Expr> >
      >
    {};

    namespace impl
    {
      // Protection against let
      template <class A, class E1, class Pred, class Body>
      struct let_impl<A, E1, catch_<A, Pred, Body> > : catch_<A, Pred, Body> {};

      template <class A, class E1, class Pred, class Body>
      struct let_impl<A, E1, catch_c<A, Pred, Body> >:catch_c<A, Pred, Body> {};
    }
  }
}

#endif

