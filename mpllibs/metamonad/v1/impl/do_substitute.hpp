#ifndef MPLLIBS_METAMONAD_V1_IMPL_DO_SUBSTITUTE_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_DO_SUBSTITUTE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/return_.hpp>
#include <mpllibs/metamonad/v1/returns.hpp>
#include <mpllibs/metamonad/v1/do_return.hpp>

#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        // I can't use let, because I should not stop at let expressions.
        // Nested do_'s are not important, since they should be used by
        // accessing a nested apply template, and do_substitute doesn't
        // recurse into that.
        // Using boost::mpl::apply and do_ together is not supported
        template <class Monad, class T>
        struct do_substitute : returns<T> {};

        template <class Monad, class T>
        struct do_substitute<Monad, do_return<T> > :
        returns<return_<Monad, typename do_substitute<Monad, T>::type> >
        {};
      
        // When an outer do_ has already substituted this do_return,
        // we need to re-substitute it. I couldn't find a way of preventing
        // substitution of inner do_'s do_returns.
        template <class Monad1, class Monad2, class T>
        struct do_substitute<Monad1, return_<Monad2, T> > :
          returns<return_<Monad1, typename do_substitute<Monad1, T>::type> >
        {};

        #ifdef MPLLIBS_DO_REC_CASE
        #  error MPLLIBS_DO_REC_CASE alread defined
        #endif
        #define MPLLIBS_DO_REC_CASE(z, n, unused) \
          typename do_substitute<Monad, BOOST_PP_CAT(X, n)>::type

        #ifdef MPLLIBS_DO_TEMPLATE_CASE
        #  error MPLLIBS_DO_TEMPLATE_CASE already defined
        #endif
        #define MPLLIBS_DO_TEMPLATE_CASE(z, n, unused) \
          template < \
            class Monad, \
            template<BOOST_PP_ENUM(n, class BOOST_PP_TUPLE_EAT(3), ~) > \
              class T, \
            BOOST_PP_ENUM_PARAMS(n, class X) \
          > \
          struct do_substitute<Monad, T<BOOST_PP_ENUM_PARAMS(n, X)> > : \
            returns<T<BOOST_PP_ENUM(n, MPLLIBS_DO_REC_CASE, ~)> > \
          {};
      
        BOOST_PP_REPEAT_FROM_TO(
          1,
          BOOST_PP_INC(BOOST_MPL_LIMIT_METAFUNCTION_ARITY),
          MPLLIBS_DO_TEMPLATE_CASE,
          ~
        )

        #undef MPLLIBS_DO_TEMPLATE_CASE
        #undef MPLLIBS_DO_REC_CASE
      }
    }
  }
}

#endif

