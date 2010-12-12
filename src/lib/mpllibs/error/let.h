// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#ifndef MPLLIBS_ERROR_LET_H
#define MPLLIBS_ERROR_LET_H

#include <mpllibs/error/util/id.h>

#include <boost/preprocessor/repetition.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>

namespace mpllibs
{
  namespace error
  {
    template <class a, class e1, class e2>
    struct let_impl;

    template <class a, class e1, class e2>
    struct let : let_impl<a, e1, e2> {};

    template <class a, class e1>
    struct let<a, e1, a> : mpllibs::error::util::id<e1> {};

    
    // let_impl assumes, that let_impl<a, e1, a> is never instantiated
    template <class a, class e1, class e2>
    struct let_impl : mpllibs::error::util::id<e2> {};

    #ifndef LET_MAX_TEMPLATE_ARGUMENT
      #define LET_MAX_TEMPLATE_ARGUMENT 10
    #endif
    
    #ifdef LET_CLASS
      #error LET_CLASS alread defined
    #endif
    #define LET_CLASS(z, n, unused) \
      , class
    
    #ifdef LET_REC_CASE
      #error LET_REC_CASE alread defined
    #endif
    #define LET_REC_CASE(z, n, unused) \
      BOOST_PP_COMMA_IF(n) typename let<a, e1, x##n>::type

    #ifdef LET_TEMPLATE_CASE
      #error LET_TEMPLATE_CASE already defined
    #endif
    // I need at least one template argument. The "n"th case handles n+1 args.
    #define LET_TEMPLATE_CASE(z, n, unused) \
      template < \
        class a, \
        class e1, \
        template<class BOOST_PP_REPEAT(n, LET_CLASS, ~) > class t, \
        class y BOOST_PP_COMMA_IF(n) \
        BOOST_PP_ENUM_PARAMS(n, class x) \
      > \
      struct \
        let_impl< \
          a, \
          e1, \
          t<y BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_PARAMS(n, x)> \
        > : \
          mpllibs::error::util::id< \
            t< \
              typename let<a, e1, y>::type BOOST_PP_COMMA_IF(n) \
              BOOST_PP_REPEAT(n, LET_REC_CASE, ~) \
            > \
          > \
      {};
    
    BOOST_PP_REPEAT(LET_MAX_TEMPLATE_ARGUMENT, LET_TEMPLATE_CASE, ~)

    #undef LET_TEMPLATE_CASE
    #undef LET_CLASS
    #undef LET_REC_CASE
  }
}

#endif

