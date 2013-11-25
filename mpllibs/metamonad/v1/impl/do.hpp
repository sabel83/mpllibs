#ifndef MPLLIBS_METAMONAD_V1_IMPL_DO_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_DO_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/limit_do_size.hpp>
#include <mpllibs/metamonad/v1/lambda_c.hpp>
#include <mpllibs/metamonad/v1/monad.hpp>
#include <mpllibs/metamonad/v1/apply.hpp>
#include <mpllibs/metamonad/v1/set.hpp>

#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        /*
         * do1
         */
        // This case handles nullary metafunction elements of the do
        template <class Monad, class E>
        struct do1 : E {};
  
        template <class Monad, class Name, class F>
        struct do1<Monad, set<Name, F> >;
          // Error: last statement in a 'do' construct must be an expression.
          // Current way of error handling is not having an implementation.
          // It may be improved.
        
        /*
         * don
         */
        #ifdef MPLLIBS_DO_CASE
        #  error MPLLIBS_DO_CASE already defined
        #endif
        // I need at least one template argument. The "n"th case handles n+1 args.
        #define MPLLIBS_DO_CASE(z, n, unused) \
          template < \
            class Monad, \
            class T BOOST_PP_COMMA_IF(BOOST_PP_DEC(n)) \
            BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(n), class E) \
          > \
          struct BOOST_PP_CAT(do, n) : \
            apply< \
              typename monad<Monad>::bind_, \
              T, \
              BOOST_PP_CAT(do, BOOST_PP_DEC(n))< \
                Monad, \
                BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(n), E) \
              > \
            > \
          {}; \
          \
          template < \
            class Monad, \
            class Name, \
            class Ex BOOST_PP_COMMA_IF(BOOST_PP_DEC(n)) \
            BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(n), class E) \
          > \
          struct BOOST_PP_CAT(do, n)< \
            Monad, \
            set<Name, Ex> BOOST_PP_COMMA_IF(BOOST_PP_DEC(n)) \
            BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(n), E) \
          > : \
            apply< \
              typename monad<Monad>::bind, \
              do1<Monad, Ex>, \
              lambda_c< \
                Name, \
                BOOST_PP_CAT(do, BOOST_PP_DEC(n))< \
                  Monad, \
                  BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(n), E) \
                > \
              > \
            > \
          {};
        
        BOOST_PP_REPEAT_FROM_TO(2,MPLLIBS_LIMIT_DO_SIZE, MPLLIBS_DO_CASE, ~)
        
        #undef MPLLIBS_DO_CASE
      }
    }
  }
}

#endif

