#ifndef MPLLIBS_PARSER_ONE_OF_H
#define MPLLIBS_PARSER_ONE_OF_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/nothing.h>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/apply.hpp>

#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

#ifndef PARSER_ONE_OF_MAX_ARGUMENT
  #define PARSER_ONE_OF_MAX_ARGUMENT 20
#endif

namespace mpllibs
{
  namespace metaparse
  {
    #ifdef PARSER_ONE_OF_BODY_PREFIX
      #error PARSER_ONE_OF_BODY_PREFIX already defined
    #endif
    #define PARSER_ONE_OF_BODY_PREFIX(z, n, unused) \
      boost::mpl::eval_if< \
        typename boost::mpl::not_< \
          typename boost::mpl::equal_to< \
            typename boost::mpl::apply<p##n, S>::type, \
            mpllibs::metaparse::nothing \
          >::type \
        >::type, \
        boost::mpl::apply<p##n, S>, \
    
    #ifdef PARSER_ONE_OF_BODY_POSTFIX
      #error PARSER_ONE_OF_BODY_POSTFIX already defined
    #endif
    #define PARSER_ONE_OF_BODY_POSTFIX(z, n, unused) \
      >
  
    #ifdef PARSER_ONE_OF_CLASSES
      #error PARSER_ONE_OF_CLASSES already defined
    #endif
    #define PARSER_ONE_OF_CLASSES(z, n, unused) class p##n ,
  
    #ifdef MPLLIBS_PARSER_ONE_OF
      #error MPLLIBS_PARSER_ONE_OF already defined
    #endif
    // We need mock otherwise n = 0 wouldn't compile
    #define MPLLIBS_PARSER_ONE_OF(z, n, unused) \
      template <BOOST_PP_REPEAT(n, PARSER_ONE_OF_CLASSES, ~) class mock = int> \
      struct one_of_##n \
      { \
        template <class S> \
        struct apply : \
          BOOST_PP_REPEAT(n, PARSER_ONE_OF_BODY_PREFIX, ~) \
            mpllibs::metaparse::nothing \
          BOOST_PP_REPEAT(n, PARSER_ONE_OF_BODY_POSTFIX, ~) \
        {}; \
      };
    
    BOOST_PP_REPEAT(PARSER_ONE_OF_MAX_ARGUMENT, MPLLIBS_PARSER_ONE_OF, ~)
    
    #undef MPLLIBS_PARSER_ONE_OF
    #undef PARSER_ONE_OF_CLASSES
    #undef PARSER_ONE_OF_BODY_POSTFIX
    #undef PARSER_ONE_OF_BODY_PREFIX
    
    struct unused_one_of_argument;
  
    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        PARSER_ONE_OF_MAX_ARGUMENT,
        class p,
        mpllibs::metaparse::unused_one_of_argument
      ),
      class mock = int
    >
    struct one_of;
    
    #ifdef PARSER_ONE_OF_UNUSED_PARAM
      #error PARSER_ONE_OF_UNUSED_PARAM already defined
    #endif
    #define PARSER_ONE_OF_UNUSED_PARAM(z, n, unused) \
      BOOST_PP_COMMA_IF(n) mpllibs::metaparse::unused_one_of_argument
    
    #ifdef PARSER_ONE_OF_CASE
      #error PARSER_ONE_OF_CASE already defined
    #endif
    #define PARSER_ONE_OF_CASE(z, n, unused) \
      template <BOOST_PP_ENUM_PARAMS(n, class p)> \
      struct one_of< \
        BOOST_PP_ENUM_PARAMS(n, p) \
        BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT( \
          BOOST_PP_SUB(PARSER_ONE_OF_MAX_ARGUMENT, n), \
          PARSER_ONE_OF_UNUSED_PARAM, \
          ~ \
        ) \
      > : \
        mpllibs::metaparse::one_of_##n<BOOST_PP_ENUM_PARAMS(n, p)> \
      {};
    
    BOOST_PP_REPEAT(PARSER_ONE_OF_MAX_ARGUMENT, PARSER_ONE_OF_CASE, ~)
    
    #undef PARSER_ONE_OF_CASE
    #undef PARSER_ONE_OF_UNUSED_PARAM
  }
}

#endif

