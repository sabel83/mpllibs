#ifndef MPLLIBS_METAMONAD_CASE_HPP
#define MPLLIBS_METAMONAD_CASE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/maybe.hpp>

#include <mpllibs/metamonad/match.hpp>
#include <mpllibs/metamonad/match_let.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/exception_core.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/is_exception.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/already_lazy.hpp>
#include <mpllibs/metamonad/lazy_protect_args.hpp>
#include <mpllibs/metamonad/eval_let.hpp>

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

    namespace impl
    {
      template <class T>
      struct get_just_data;

      template <class T>
      struct get_just_data<just<T> > : returns<T> {};

      template <class E, class C>
      struct case_check_match;

      template <class P, class E1, class E2>
      struct case_check_match<E1, matches<P, E2> > :
        boost::mpl::eval_if<
          typename is_exception<
            typename match<P, typename E1::type>::type
          >::type,
          nothing,
          match_let<P, E1, just<E2> >
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
        r,
        boost::mpl::fold<
          boost::mpl::vector<BOOST_PP_ENUM_PARAMS(MPLLIBS_LIMIT_CASE_SIZE, C)>,
          nothing,
          lambda<s, c,
            // s:
            //  nothing -> no case matched so far
            //  just<X> -> a case matched, the result is X
            lazy<
              boost::mpl::eval_if<
                boost::mpl::and_<
                  lazy_protect_args<boost::is_same<nothing, s> >,
                  boost::mpl::not_<
                    lazy_protect_args<boost::is_same<no_case, c> >
                  >
                >,
                lazy_protect_args<impl::case_check_match<E, c> >,
                lazy_protect_args<returns<s> >
              >
            >
          >
        >,
        lazy<
          boost::mpl::eval_if<
            boost::is_same<nothing, lazy_protect_args<r> >,
            exception<no_case_matched<lazy_protect_args<E> > >,
            impl::get_just_data<lazy_protect_args<r> >
          >
        >
      >
    {};
  }
}

#endif

