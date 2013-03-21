#ifndef MPLLIBS_METAPARSE_ONE_OF_HPP
#define MPLLIBS_METAPARSE_ONE_OF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/fail.hpp>

#include <boost/mpl/if.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/string.hpp>

#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

#ifndef MPLLIBS_ONE_OF_MAX_ARGUMENT
  #define MPLLIBS_ONE_OF_MAX_ARGUMENT 20
#endif

namespace mpllibs
{
  namespace metaparse
  {
    namespace errors
    {
      typedef
        boost::mpl::string<
          'none',' of ','the ','expe','cted',' cas','es f','ound'
        >
        none_of_the_expected_cases_found;
    }
  
    #ifdef MPLLIBS_ONE_OF_BODY_PREFIX
      #error MPLLIBS_ONE_OF_BODY_PREFIX already defined
    #endif
    #define MPLLIBS_ONE_OF_BODY_PREFIX(z, n, unused) \
      typename boost::mpl::if_< \
        boost::mpl::not_< \
          typename is_error<boost::mpl::apply<P##n, S, Pos> >::type \
        >, \
        P##n, \
    
    #ifdef MPLLIBS_ONE_OF_BODY_POSTFIX
      #error MPLLIBS_ONE_OF_BODY_POSTFIX already defined
    #endif
    #define MPLLIBS_ONE_OF_BODY_POSTFIX(z, n, unused) \
      >::type
  
    #ifdef MPLLIBS_MPLLIBS_ONE_OF
      #error MPLLIBS_MPLLIBS_ONE_OF already defined
    #endif
    // We need mock otherwise n = 0 wouldn't compile
    #define MPLLIBS_MPLLIBS_ONE_OF(z, n, unused) \
      template < \
        BOOST_PP_ENUM_PARAMS(n, class P) \
        BOOST_PP_COMMA_IF(n) \
        class Mock = int \
      > \
      struct one_of_##n \
      { \
        typedef one_of_##n type; \
        \
        template <class S, class Pos> \
        struct apply : \
          boost::mpl::apply_wrap2< \
            BOOST_PP_REPEAT(n, MPLLIBS_ONE_OF_BODY_PREFIX, ~) \
              fail< \
                mpllibs::metaparse::errors::none_of_the_expected_cases_found \
              > \
            BOOST_PP_REPEAT(n, MPLLIBS_ONE_OF_BODY_POSTFIX, ~), \
            S, \
            Pos \
          > \
        {}; \
      };
    
    BOOST_PP_REPEAT(MPLLIBS_ONE_OF_MAX_ARGUMENT, MPLLIBS_MPLLIBS_ONE_OF, ~)
    
    #undef MPLLIBS_MPLLIBS_ONE_OF
    #undef MPLLIBS_ONE_OF_BODY_POSTFIX
    #undef MPLLIBS_ONE_OF_BODY_PREFIX
    
    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_ONE_OF_MAX_ARGUMENT,
        class P,
        boost::mpl::na
      ),
      class Mock = int
    >
    struct one_of;
    
    #ifdef MPLLIBS_ONE_OF_UNUSED_PARAM
      #error MPLLIBS_ONE_OF_UNUSED_PARAM already defined
    #endif
    #define MPLLIBS_ONE_OF_UNUSED_PARAM(z, n, unused) \
      BOOST_PP_COMMA_IF(n) boost::mpl::na
    
    #ifdef MPLLIBS_ONE_OF_CASE
      #error MPLLIBS_ONE_OF_CASE already defined
    #endif
    #define MPLLIBS_ONE_OF_CASE(z, n, unused) \
      template <BOOST_PP_ENUM_PARAMS(n, class P)> \
      struct one_of< \
        BOOST_PP_ENUM_PARAMS(n, P) \
        BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT( \
          BOOST_PP_SUB(MPLLIBS_ONE_OF_MAX_ARGUMENT, n), \
          MPLLIBS_ONE_OF_UNUSED_PARAM, \
          ~ \
        ) \
      > : one_of_##n<BOOST_PP_ENUM_PARAMS(n, P)> \
      {};
    
    BOOST_PP_REPEAT(MPLLIBS_ONE_OF_MAX_ARGUMENT, MPLLIBS_ONE_OF_CASE, ~)
    
    #undef MPLLIBS_ONE_OF_CASE
    #undef MPLLIBS_ONE_OF_UNUSED_PARAM
  }
}

#endif

