#ifndef MPLLIBS_METAPARSE_ANY_ONE_OF1_HPP
#define MPLLIBS_METAPARSE_ANY_ONE_OF1_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/any1.hpp>

#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_ONE_OF_MAX_ARGUMENT,
        class P,
        boost::mpl::na
      ),
      class Mock = int
    >
    struct any_one_of1;
    
    #ifdef MPLLIBS_ANY_ONE_OF1_UNUSED_PARAM
      #error MPLLIBS_ANY_ONE_OF1_UNUSED_PARAM already defined
    #endif
    #define MPLLIBS_ANY_ONE_OF1_UNUSED_PARAM(z, n, unused) \
      BOOST_PP_COMMA_IF(n) boost::mpl::na
    
    #ifdef MPLLIBS_ANY_ONE_OF1_CASE
      #error MPLLIBS_ANY_ONE_OF1_CASE already defined
    #endif
    #define MPLLIBS_ANY_ONE_OF1_CASE(z, n, unused) \
      template <BOOST_PP_ENUM_PARAMS(n, class P)> \
      struct any_one_of1< \
        BOOST_PP_ENUM_PARAMS(n, P) \
        BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT( \
          BOOST_PP_SUB(MPLLIBS_ONE_OF_MAX_ARGUMENT, n), \
          MPLLIBS_ANY_ONE_OF1_UNUSED_PARAM, \
          ~ \
        ) \
      > : any1<one_of_##n<BOOST_PP_ENUM_PARAMS(n, P)> > \
      {};
    
    BOOST_PP_REPEAT(MPLLIBS_ONE_OF_MAX_ARGUMENT, MPLLIBS_ANY_ONE_OF1_CASE, ~)
    
    #undef MPLLIBS_ANY_ONE_OF1_CASE
    #undef MPLLIBS_ANY_ONE_OF1_UNUSED_PARAM
  }
}

#endif

