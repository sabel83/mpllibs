#ifndef MPLLIBS_METAPARSE_V2_ONE_OF_HPP
#define MPLLIBS_METAPARSE_V2_ONE_OF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/impl/one_of.hpp>
#include <mpllibs/metaparse/v2/error/none_of_the_expected_cases_found.hpp>
#include <mpllibs/metaparse/v2/fail.hpp>
#include <mpllibs/metaparse/limit_one_of_size.hpp>

#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <
        BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
          MPLLIBS_LIMIT_ONE_OF_SIZE,
          class P,
          boost::mpl::na
        )
      >
      struct one_of;

      template <>
      struct one_of<
        BOOST_PP_ENUM(
          MPLLIBS_LIMIT_ONE_OF_SIZE,
          boost::mpl::na BOOST_PP_TUPLE_EAT(3),
          ~
        )
      > :
        fail<error::none_of_the_expected_cases_found>
      {};
      
      #ifdef MPLLIBS_ONE_OF_CASE
      #  error MPLLIBS_ONE_OF_CASE already defined
      #endif
      #define MPLLIBS_ONE_OF_CASE(z, n, unused) \
        template <BOOST_PP_ENUM_PARAMS(n, class P)> \
        struct one_of< \
          BOOST_PP_ENUM_PARAMS(n, P) \
          BOOST_PP_COMMA_IF(n) \
          BOOST_PP_ENUM( \
            BOOST_PP_SUB(MPLLIBS_LIMIT_ONE_OF_SIZE, n), \
            boost::mpl::na BOOST_PP_TUPLE_EAT(3), \
            ~ \
          ) \
        > : impl::BOOST_PP_CAT(one_of_, n)<BOOST_PP_ENUM_PARAMS(n, P)> \
        {};
      
      BOOST_PP_REPEAT_FROM_TO(
        1,
        MPLLIBS_LIMIT_ONE_OF_SIZE,
        MPLLIBS_ONE_OF_CASE,
        ~
      )
      
      #undef MPLLIBS_ONE_OF_CASE
    }
  }
}

#endif

