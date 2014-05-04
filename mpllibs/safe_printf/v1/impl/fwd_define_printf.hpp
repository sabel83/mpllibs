// Copyright Abel Sinkovics (abel@sinkovics.hu)  2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// no include guard - this header can be included multiple times

#include <mpllibs/safe_printf/printf_max_argument.hpp>

#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

#include <mpllibs/safe_printf/v1/impl/check_define_printf_args.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    namespace v1
    {
      #ifdef MPLLIBS_PRINTF_EXTRA_ARGS
      #  error MPLLIBS_PRINTF_EXTRA_ARGS already defined
      #endif
      #define MPLLIBS_PRINTF_EXTRA_ARGS(n) \
        BOOST_PP_SEQ_ENUM(MPLLIBS_DEFINE_PRINTF_ARGS) BOOST_PP_COMMA_IF(n)
      
      #ifdef MPLLIBS_PRINTF
      #  error MPLLIBS_PRINTF already defined
      #endif
      #define MPLLIBS_PRINTF(z, n, unused) \
        template < \
          class FormatString \
          BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_PARAMS(n, class T) \
        > \
        int MPLLIBS_DEFINE_PRINTF_NAME( \
          BOOST_PP_IF( \
            MPLLIBS_DEFINE_PRINTF_HAS_ARGS, \
            MPLLIBS_PRINTF_EXTRA_ARGS, \
            BOOST_PP_TUPLE_EAT(1) \
          )(n) \
          BOOST_PP_ENUM_BINARY_PARAMS(n, T, t) \
        ); \
  
      BOOST_PP_REPEAT(MPLLIBS_PRINTF_MAX_ARGUMENT, MPLLIBS_PRINTF, ~)
  
      #undef MPLLIBS_PRINTF
      #undef MPLLIBS_PRINTF_EXTRA_ARGS
    }
  }
}

