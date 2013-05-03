#ifndef MPLLIBS_METAPARSE_ONE_CHAR_EXCEPT_HPP
#define MPLLIBS_METAPARSE_ONE_CHAR_EXCEPT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/one_char.hpp>
#include <mpllibs/metaparse/accept_when.hpp>
#include <mpllibs/metaparse/define_error.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/bool.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>

#ifndef MPLLIBS_ONE_CHAR_EXCEPT_MAX_ARGUMENT
  #define MPLLIBS_ONE_CHAR_EXCEPT_MAX_ARGUMENT 10
#endif

namespace mpllibs
{
  namespace metaparse
  {
    namespace errors
    {
      MPLLIBS_DEFINE_ERROR(unexpected_character, "Unexpected character");
    }
    
    namespace impl
    {
      template <class Stub = int>
      struct is_any0
      {
        template <class C>
        struct apply : boost::mpl::true_ {};
      };

      #ifdef MPLLIBS_METAPARSE_DEFINE_IS_ANY
        #error MPLLIBS_METAPARSE_DEFINE_IS_ANY already defined
      #endif
      #define MPLLIBS_METAPARSE_DEFINE_IS_ANY(z, n, unused) \
        template <BOOST_PP_ENUM_PARAMS(n, class T)> \
        struct is_any##n \
        { \
          template <class C> \
          struct apply : \
            boost::mpl::eval_if< \
              typename boost::mpl::equal_to< \
                typename C::type, \
                typename BOOST_PP_CAT(T, BOOST_PP_DEC(n))::type \
              >::type, \
              boost::mpl::false_, \
              boost::mpl::apply_wrap1< \
                BOOST_PP_CAT(is_any, BOOST_PP_DEC(n))< \
                  BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(n), T) \
                >, \
                C \
              > \
            > \
          {}; \
        };

      BOOST_PP_REPEAT_FROM_TO(
        1,
        MPLLIBS_ONE_CHAR_EXCEPT_MAX_ARGUMENT,
        MPLLIBS_METAPARSE_DEFINE_IS_ANY,
        ~
      )

      #undef MPLLIBS_METAPARSE_DEFINE_IS_ANY

      struct one_char_except_not_used {};
    }

    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_ONE_CHAR_EXCEPT_MAX_ARGUMENT,
        class C,
        impl::one_char_except_not_used
      )
    >
    struct one_char_except;

    #ifdef MPLLIBS_METAPARSE_UNUSED
      #error MPLLIBS_METAPARSE_UNUSED already defined
    #endif
    #define MPLLIBS_METAPARSE_UNUSED(z, n, unused) \
      BOOST_PP_COMMA_IF(n) impl::one_char_except_not_used

    #ifdef MPLLBIS_METAPARSE_ONE_CHAR_EXCEPT_CASE
      #error MPLLBIS_METAPARSE_ONE_CHAR_EXCEPT_CASE already defined
    #endif
    #define MPLLBIS_METAPARSE_ONE_CHAR_EXCEPT_CASE(z, n, unused) \
      template <BOOST_PP_ENUM_PARAMS(n, class T)> \
      struct one_char_except< \
        BOOST_PP_ENUM_PARAMS(n, T) \
        BOOST_PP_REPEAT_FROM_TO( \
          n, \
          BOOST_PP_DEC(MPLLIBS_ONE_CHAR_EXCEPT_MAX_ARGUMENT), \
          MPLLIBS_METAPARSE_UNUSED, \
          ~ \
        ) \
      > :\
        accept_when< \
          one_char, \
          impl::is_any##n<BOOST_PP_ENUM_PARAMS(n, T)>, \
          errors::unexpected_character \
        > \
      {};

    BOOST_PP_REPEAT(
      MPLLIBS_ONE_CHAR_EXCEPT_MAX_ARGUMENT,
      MPLLBIS_METAPARSE_ONE_CHAR_EXCEPT_CASE,
      ~
    )

    #undef MPLLBIS_METAPARSE_ONE_CHAR_EXCEPT_CASE
    #undef MPLLIBS_METAPARSE_UNUSED
  }
}

#endif

