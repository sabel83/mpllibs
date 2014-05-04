// Copyright Abel Sinkovics (abel@sinkovics.hu)  2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// no include guard - this header can be included multiple times

#include <mpllibs/safe_printf/v1/valid_arguments.hpp>

#include <boost/mpl/string.hpp>
#include <boost/mpl/vector.hpp>

#include <boost/static_assert.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

#include <mpllibs/safe_printf/v1/impl/check_define_printf_args.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    namespace v1
    {
      #ifdef MPLLIBS_PRINTF_TEMPLATE
      #  error MPLLIBS_PRINTF_TEMPLATE already defined
      #endif
      #define MPLLIBS_PRINTF_TEMPLATE(n) \
        template < \
          class FormatString \
          BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_PARAMS(n, class T) \
        >
  
      #ifdef MPLLIBS_PRINTF_BOX
      #  error MPLLIBS_PRINTF_BOX already defined
      #endif
      #define MPLLIBS_PRINTF_BOX(z, n, unused) \
        metamonad::box<BOOST_PP_CAT(T, n)>
  
      #ifdef MPLLIBS_PRINTF_ASSERT
      #  error MPLLIBS_PRINTF_ASSERT already defined
      #endif
      #define MPLLIBS_PRINTF_ASSERT(n) \
        BOOST_STATIC_ASSERT(( \
          valid_arguments< \
            FormatString, \
            boost::mpl::vector<BOOST_PP_ENUM(n, MPLLIBS_PRINTF_BOX, ~)> \
          >::type::value \
        )) \
  
      #ifdef MPLLIBS_PRINTF_ARGS
      #  error MPLLIBS_PRINTF_ARGS already defined
      #endif
      #define MPLLIBS_PRINTF_ARGS(n) \
        boost::mpl::c_str<FormatString>::type::value BOOST_PP_COMMA_IF(n) \
        BOOST_PP_ENUM_PARAMS(n, t) \

      #ifdef MPLLIBS_PRINTF_DEF_ARG
      #  error MPLLIBS_PRINTF_DEF_ARG already defined
      #endif
      #define MPLLIBS_PRINTF_DEF_ARG(r, data, i, elem) \
        BOOST_PP_COMMA_IF(i) elem BOOST_PP_CAT(arg, i)

      #ifdef MPLLIBS_PRINTF_EXTRA_ARGS
      #  error MPLLIBS_PRINTF_EXTRA_ARGS already defined
      #endif
      #define MPLLIBS_PRINTF_EXTRA_ARGS(n) \
        BOOST_PP_SEQ_FOR_EACH_I( \
          MPLLIBS_PRINTF_DEF_ARG, \
          ~, \
          MPLLIBS_DEFINE_PRINTF_ARGS \
        ) BOOST_PP_COMMA_IF(n)
      
      #ifdef MPLLIBS_PRINTF_CALL_WITH_EXTRA_ARGS
      #  error MPLLIBS_PRINTF_CALL_WITH_EXTRA_ARGS already defined
      #endif
      #define MPLLIBS_PRINTF_CALL_WITH_EXTRA_ARGS(n) \
        BOOST_PP_ENUM_PARAMS( \
          BOOST_PP_SEQ_SIZE(MPLLIBS_DEFINE_PRINTF_ARGS), \
          arg \
        ) \
        BOOST_PP_COMMA_IF(BOOST_PP_SEQ_SIZE(MPLLIBS_DEFINE_PRINTF_ARGS))

      #ifdef MPLLIBS_PRINTF
      #  error MPLLIBS_PRINTF already defined
      #endif
      #define MPLLIBS_PRINTF(z, n, unused) \
        MPLLIBS_PRINTF_TEMPLATE(n) \
        int MPLLIBS_DEFINE_PRINTF_NAME( \
          BOOST_PP_IF( \
            MPLLIBS_DEFINE_PRINTF_HAS_ARGS, \
            MPLLIBS_PRINTF_EXTRA_ARGS, \
            BOOST_PP_TUPLE_EAT(1) \
          )(n) \
          BOOST_PP_ENUM_BINARY_PARAMS(n, T, t) \
        ) \
        { \
          MPLLIBS_PRINTF_ASSERT(n); \
          return \
            ::MPLLIBS_DEFINE_PRINTF_NAME( \
              BOOST_PP_IF( \
                MPLLIBS_DEFINE_PRINTF_HAS_ARGS, \
                MPLLIBS_PRINTF_CALL_WITH_EXTRA_ARGS, \
                BOOST_PP_TUPLE_EAT(1) \
              )(n) \
              MPLLIBS_PRINTF_ARGS(n) \
            ); \
        } \
  
      #ifdef _MSC_VER
      #  pragma warning(push)
      #  pragma warning(disable: 4996)
      #endif
  
      BOOST_PP_REPEAT(MPLLIBS_PRINTF_MAX_ARGUMENT, MPLLIBS_PRINTF, ~)
  
      #ifdef _MSC_VER
      #  pragma warning(pop)
      #endif
      
      #undef MPLLIBS_PRINTF
      #undef MPLLIBS_PRINTF_BOX
      #undef MPLLIBS_PRINTF_ARGS
      #undef MPLLIBS_PRINTF_ASSERT
      #undef MPLLIBS_PRINTF_CALL_WITH_EXTRA_ARGS
      #undef MPLLIBS_PRINTF_DEF_ARG
      #undef MPLLIBS_PRINTF_EXTRA_ARGS
      #undef MPLLIBS_PRINTF_TEMPLATE
    }
  }
}

