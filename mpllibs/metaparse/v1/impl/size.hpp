#ifndef MPLLIBS_METAPARSE_V1_IMPL_SIZE_HPP
#define MPLLIBS_METAPARSE_V1_IMPL_SIZE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/config.hpp>
#include <mpllibs/metaparse/v1/fwd/string.hpp>

#include <boost/mpl/int.hpp>

#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace impl
      {
        template <class S>
        struct size;

#ifdef MPLLIBS_VARIADIC_STRING
        template <char... Cs>
        struct size<string<Cs...>> : boost::mpl::int_<sizeof...(Cs)> {};
#else
        #ifdef MPLLIBS_STRING_CASE
        #  error MPLLIBS_STRING_CASE
        #endif
        #define MPLLIBS_STRING_CASE(z, n, unused) \
          template <BOOST_PP_ENUM_PARAMS(n, int C)> \
          struct \
            size< \
              string< \
                BOOST_PP_ENUM_PARAMS(n, C) BOOST_PP_COMMA_IF(n) \
                BOOST_PP_ENUM( \
                  BOOST_PP_SUB(MPLLIBS_LIMIT_STRING_SIZE, n), \
                  MPLLIBS_NO_CHAR BOOST_PP_TUPLE_EAT(3), \
                  ~ \
                ) \
              > \
            > : \
            boost::mpl::int_<n> \
          {};
  
        BOOST_PP_REPEAT(MPLLIBS_LIMIT_STRING_SIZE, MPLLIBS_STRING_CASE, ~)
  
        #undef MPLLIBS_STRING_CASE
#endif
      }
    }
  }
}

#endif

