#ifndef MPLLIBS_METAPARSE_LAST_OF_HPP
#define MPLLIBS_METAPARSE_LAST_OF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/nth_of.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_SEQUENCE_MAX_ARGUMENT,
        class P,
        boost::mpl::na
      )
    >
    struct last_of;


    #ifdef MPLLIBS_SEQUENCE_UNUSED_PARAM
      #error MPLLIBS_SEQUENCE_UNUSED_PARAM already defined
    #endif
    #define MPLLIBS_SEQUENCE_UNUSED_PARAM(z, n, unused) \
      BOOST_PP_COMMA_IF(n) boost::mpl::na
    
    #ifdef MPLLIBS_LAST_OF_N
      #error MPLLIBS_LAST_OF_N already defined
    #endif
    #define MPLLIBS_LAST_OF_N(z, n, unused) \
      template <BOOST_PP_ENUM_PARAMS(n, class P)> \
      struct last_of< \
        BOOST_PP_ENUM_PARAMS(n, P) \
        BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT( \
          BOOST_PP_SUB(MPLLIBS_SEQUENCE_MAX_ARGUMENT, n), \
          MPLLIBS_SEQUENCE_UNUSED_PARAM, \
          ~ \
        ) \
      > : nth_of_c##n<n - 1 BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_PARAMS(n, P)> \
      {};
    
    BOOST_PP_REPEAT(MPLLIBS_SEQUENCE_MAX_ARGUMENT, MPLLIBS_LAST_OF_N, ~)
    
    #undef MPLLIBS_LAST_OF_N
    #undef MPLLIBS_SEQUENCE_UNUSED_PARAM
  }
}

#endif

