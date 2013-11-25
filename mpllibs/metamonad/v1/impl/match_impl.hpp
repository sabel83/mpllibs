#ifndef MPLLIBS_METAMONAD_V1_IMPL_MATCH_IMPL_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_MATCH_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/exception.hpp>

#include <mpllibs/metamonad/v1/impl/match_boxed_impl.hpp>

#include <mpllibs/metamonad/v1/bad_match.hpp>
#include <mpllibs/metamonad/v1/syntax.hpp>
#include <mpllibs/metamonad/v1/box.hpp>

#include <boost/mpl/vector.hpp>

#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/cat.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        template <class Pattern, class Value>
        struct match_impl :
          exception<bad_match<syntax<Pattern>, syntax<Value> > >
        {};

        #ifdef MPLLIBS_WRAPPED
        #  error MPLLIBS_WRAPPED already defined
        #endif
        #define MPLLIBS_WRAPPED(z, n, name) box<BOOST_PP_CAT(name, n)>

        #ifdef MPLLIBS_MATCH_TEMPLATE
        #  error MPLLIBS_MATCH_TEMPLATE already defined
        #endif
        #define MPLLIBS_MATCH_TEMPLATE(z, n, unused) \
          template < \
            template <BOOST_PP_ENUM(n,class BOOST_PP_TUPLE_EAT(3),~)> class T, \
            BOOST_PP_ENUM_PARAMS(n, class P), \
            BOOST_PP_ENUM_PARAMS(n, class V) \
          > \
          struct \
            match_impl< \
              T<BOOST_PP_ENUM_PARAMS(n, P)>, T<BOOST_PP_ENUM_PARAMS(n, V)> \
            > : \
            match_boxed_impl< \
              boost::mpl::vector<BOOST_PP_ENUM(n, MPLLIBS_WRAPPED, P)>, \
              boost::mpl::vector<BOOST_PP_ENUM(n, MPLLIBS_WRAPPED, V)> \
            > \
          {};

        BOOST_PP_REPEAT_FROM_TO(
          1,
          BOOST_MPL_LIMIT_METAFUNCTION_ARITY,
          MPLLIBS_MATCH_TEMPLATE,
          ~
        )

        #undef MPLLIBS_MATCH_TEMPLATE
        #undef MPLLIBS_WRAPPED
      }
    }
  }
}

#endif

