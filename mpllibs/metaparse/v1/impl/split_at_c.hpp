#ifndef MPLLIBS_METAPARSE_V1_IMPL_SPLIT_AT_C_HPP
#define MPLLIBS_METAPARSE_V1_IMPL_SPLIT_AT_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/config.hpp>
#include <mpllibs/metaparse/v1/fwd/string.hpp>
#include <mpllibs/metaparse/v1/impl/push_front_c.hpp>

#include <boost/preprocessor/arithmetic/add.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

#include <boost/mpl/pair.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace impl
      {
        template <int N, class S>
        struct split_at_c;

#ifdef MPLLIBS_VARIADIC_STRING
        template <int N, char C, char... Cs>
        struct split_at_c<N, string<C, Cs...>> :
          boost::mpl::pair<
            typename push_front_c<
              typename split_at_c<N - 1, string<Cs...>>::type::first,
              C
            >::type,
            typename split_at_c<N - 1, string<Cs...>>::type::second
          >
        {};

        template <char C, char... Cs>
        struct split_at_c<0, string<C, Cs...>> :
          boost::mpl::pair<string<>, string<C, Cs...>>
        {};

        template <char... Cs>
        struct split_at_c<0, string<Cs...>> :
          boost::mpl::pair<string<>, string<Cs...>>
        {};
#else
        #ifdef MPLLIBS_ARG
        #  error MPLLIBS_ARG already defined
        #endif
        #define MPLLIBS_ARG(z, n, d) BOOST_PP_CAT(C, BOOST_PP_ADD(n, d))

        #ifdef MPLLIBS_SPLIT_AT
        #  error MPLLIBS_SPLIT_AT already defined
        #endif
        #define MPLLIBS_SPLIT_AT(z, n, unused) \
          template <BOOST_PP_ENUM_PARAMS(MPLLIBS_LIMIT_STRING_SIZE, int C)> \
          struct \
            split_at_c< \
              n, \
              string<BOOST_PP_ENUM_PARAMS(MPLLIBS_LIMIT_STRING_SIZE, C)> \
            > : \
            boost::mpl::pair< \
              string<BOOST_PP_ENUM_PARAMS(n, C)>, \
              string< \
                BOOST_PP_ENUM( \
                  BOOST_PP_SUB(MPLLIBS_LIMIT_STRING_SIZE, n), \
                  MPLLIBS_ARG, \
                  n \
                ) \
              > \
            > \
          {};

        BOOST_PP_REPEAT(MPLLIBS_LIMIT_STRING_SIZE, MPLLIBS_SPLIT_AT, ~)

        #undef MPLLIBS_SPLIT_AT
        #undef MPLLIBS_ARG
#endif
      }
    }
  }
}

#endif

