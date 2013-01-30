#ifndef MPLLIBS_METAMONAD_CASE_HPP
#define MPLLIBS_METAMONAD_CASE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/maybe.hpp>

#include <mpllibs/metamonad/match.hpp>
#include <mpllibs/metamonad/eval_match_let.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/exception_core.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/is_exception.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/already_lazy.hpp>
#include <mpllibs/metamonad/lazy_protect_args.hpp>
#include <mpllibs/metamonad/lazy_argument.hpp>
#include <mpllibs/metamonad/eval_let.hpp>
#include <mpllibs/metamonad/eval_syntax.hpp>

#include <boost/mpl/fold.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>

#include <boost/type_traits.hpp>

#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

#ifndef MPLLIBS_LIMIT_CASE_SIZE
  #define MPLLIBS_LIMIT_CASE_SIZE 8 
#endif

namespace mpllibs
{
  namespace metamonad
  {
    struct no_case;

    MPLLIBS_METAFUNCTION(no_case_matched, (Exp))
    ((tmp_value<no_case_matched<Exp> >));

    template <class P, class E>
    struct matches;

    template <class P, class E>
    struct matches_c;

    namespace impl
    {
      // Custom names are needed to avoid "let"'s A be the same as one of the
      // names used
      struct let_case_c_;
      struct let_case_r_;
      struct let_case_s_;

      typedef var<let_case_c_> let_case_c;
      typedef var<let_case_r_> let_case_r;
      typedef var<let_case_s_> let_case_s;

      template <class T>
      struct get_just_data;

      template <class T>
      struct get_just_data<just<T> > : returns<T> {};

      template <class E, class C>
      struct case_check_match;

      template <class P, class E1, class E2>
      struct case_check_match<E1, matches_c<P, E2> > :
        case_check_match<E1, matches<syntax<P>, syntax<E2> > >
      {};

      template <class P, class E1, class E2>
      struct case_check_match<E1, matches<P, E2> > :
        boost::mpl::eval_if<
          typename is_exception<
            typename match<typename P::type, typename E1::type>::type
          >::type,
          nothing,
          just<
            match_let<typename P::type, typename E1::type, typename E2::type>
          >
        >
      {};
    }

    template <
      class E,
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_LIMIT_CASE_SIZE,
        class C,
        no_case
      )
    >
    struct case_ :
      eval_let<
        impl::let_case_r,
        syntax<
          boost::mpl::fold<
            boost::mpl::vector<BOOST_PP_ENUM_PARAMS(MPLLIBS_LIMIT_CASE_SIZE, C)>,
            nothing,
            lambda_c<impl::let_case_s, impl::let_case_c,
              // s:
              //  nothing -> no case matched so far
              //  just<X> -> a case matched, the result is X
              lazy<
                boost::mpl::eval_if<
                  boost::mpl::and_<
                    lazy_protect_args<
                      boost::is_same<nothing, impl::let_case_s>
                    >,
                    boost::mpl::not_<
                      lazy_protect_args<
                        boost::is_same<no_case, impl::let_case_c>
                      >
                    >
                  >,
                  already_lazy<impl::case_check_match<E, impl::let_case_c> >,
                  already_lazy<returns<impl::let_case_s> >
                >
              >
            >
          >
        >,
        syntax<
          lazy<
            boost::mpl::eval_if<
              boost::is_same<nothing, lazy_protect_args<impl::let_case_r> >,
              lazy_argument<
                exception<no_case_matched<lazy_protect_args<E> > >
              >,
              lazy_argument<
                impl::get_just_data<lazy_protect_args<impl::let_case_r> >
              >
            >
          >
        >
      >
    {};
  }
}

#endif

