#ifndef MPLLIBS_METAPARSE_V1_SEQUENCE_HPP
#define MPLLIBS_METAPARSE_V1_SEQUENCE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/impl/sequence.hpp>

#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      template <
        BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
          MPLLIBS_LIMIT_SEQUENCE_SIZE,
          class P,
          boost::mpl::na
        )
      >
      struct sequence;

      #ifdef MPLLIBS_SEQUENCE_N
      #  error MPLLIBS_SEQUENCE_N already defined
      #endif
      #define MPLLIBS_SEQUENCE_N(z, n, unused) \
        template <BOOST_PP_ENUM_PARAMS(n, class P)> \
        struct sequence< \
          BOOST_PP_ENUM_PARAMS(n, P) \
          BOOST_PP_COMMA_IF(n) \
          BOOST_PP_ENUM( \
            BOOST_PP_SUB(MPLLIBS_LIMIT_SEQUENCE_SIZE, n), \
            boost::mpl::na BOOST_PP_TUPLE_EAT(3), \
            ~ \
          ) \
        > : impl::BOOST_PP_CAT(sequence, n)<BOOST_PP_ENUM_PARAMS(n, P)> \
        {};
      
      BOOST_PP_REPEAT_FROM_TO(
        1,
        MPLLIBS_LIMIT_SEQUENCE_SIZE,
        MPLLIBS_SEQUENCE_N,
        ~
      )
      
      #undef MPLLIBS_SEQUENCE_N
    }
  }
}

#endif

