#ifndef MPLLIBS_METAMONAD_CASE_HPP
#define MPLLIBS_METAMONAD_CASE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/match.hpp>
#include <mpllibs/metamonad/match_let.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/throw.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>
#include <mpllibs/metamonad/maybe.hpp>
#include <mpllibs/metamonad/is_nothing.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/is_exception.hpp>
#include <mpllibs/metamonad/get_data.hpp>

#include <boost/mpl/fold.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>

#include <boost/type_traits.hpp>

#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

#ifndef MPLLIBS_LIMIT_CASE_SIZE
  #define MPLLIBS_LIMIT_CASE_SIZE 16
#endif

namespace mpllibs
{
  namespace metamonad
  {
    struct no_case;

    struct no_case_matched : tmp_value<no_case_matched> {};

    template <class P, class E>
    struct matches;

    namespace impl
    {
      template <class E, class C>
      struct case_check_match;

      template <class P, class E1, class E2>
      struct case_check_match<E1, matches<P, E2> > :
        boost::mpl::eval_if<
          typename is_exception<typename match<P, E1>::type>::type,
          nothing,
          match_let<P, E1, just<E2> >
        >
      {};

      // S:
      //  nothing -> no case matched so far
      //  just<X> -> a case matched, the result is X
      template <class E>
      MPLLIBS_METAFUNCTION_CLASS(case_cb, (S)(C))
      ((
        boost::mpl::eval_if<
          typename boost::mpl::and_<
            typename is_nothing<S>::type,
            typename boost::mpl::not_<
              typename boost::is_same<no_case, C>::type
            >::type
          >::type,
          case_check_match<E, C>,
          returns<S>
        >
      ));

      MPLLIBS_LAZY_METAFUNCTION(case_impl, (R))
      ((
        typename boost::mpl::eval_if<
          typename is_nothing<R>::type,
          throw_<no_case_matched>,
          get_data<R>
        >::type
      ));
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
      impl::case_impl<
        boost::mpl::fold<
          boost::mpl::vector<BOOST_PP_ENUM_PARAMS(MPLLIBS_LIMIT_CASE_SIZE, C)>,
          nothing,
          impl::case_cb<E>
        >
      >
    {};
  }
}

#endif

