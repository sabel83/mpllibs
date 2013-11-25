#ifndef MPLLIBS_METAMONAD_V1_DO_C_HPP
#define MPLLIBS_METAMONAD_V1_DO_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/do_c.hpp>

#include <mpllibs/metamonad/v1/impl/let_do_args.hpp>
#include <mpllibs/metamonad/v1/impl/do.hpp>
#include <mpllibs/metamonad/v1/impl/do_substitute.hpp>

#include <mpllibs/metamonad/v1/eval_match_let.hpp>
#include <mpllibs/metamonad/v1/instantiate.hpp>
#include <mpllibs/metamonad/v1/pair.hpp>
#include <mpllibs/metamonad/v1/apply.hpp>

#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/push_front.hpp>

#if MPLLIBS_LIMIT_DO_SIZE > MPLLIBS_LIMIT_METAFUNCTION_ARITY - 2
#  error BOOST_MPL_LIMIT_DO_SIZE too large
#endif

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      #ifdef MPLLIBS_DO_ARG
      #  error MPLLIBS_DO_ARG already defined
      #endif
      #define MPLLIBS_DO_ARG(z, n, unused) \
        , typename impl::do_substitute<Monad, BOOST_PP_CAT(E, n)>::type
       
      #ifdef MPLLIBS_DO_CASE
      #  error MPLLIBS_DO_CASE already defined
      #endif
      #define MPLLIBS_DO_CASE(z, n, unused) \
        template <class Monad, BOOST_PP_ENUM_PARAMS(n, class E)> \
        struct do_c< \
          Monad, \
          BOOST_PP_ENUM_PARAMS(n, E) BOOST_PP_COMMA_IF(n) \
          BOOST_PP_ENUM( \
            BOOST_PP_SUB(MPLLIBS_LIMIT_DO_SIZE, n), \
            boost::mpl::na BOOST_PP_TUPLE_EAT(3), \
            ~ \
          ) \
        > : \
          BOOST_PP_CAT(impl::do, n)< \
            Monad \
            BOOST_PP_REPEAT(n, MPLLIBS_DO_ARG, ~) \
          > \
        {};
  
      BOOST_PP_REPEAT_FROM_TO(1, MPLLIBS_LIMIT_DO_SIZE, MPLLIBS_DO_CASE, ~)
      
      #undef MPLLIBS_DO_CASE
      #undef MPLLIBS_DO_ARG

      /*
        Protection against let
      */
      namespace impl
      {
        #ifdef MPLLIBS_HANDLE_DO_FUN
        #  error MPLLIBS_HANDLE_DO_FUN
        #endif
        #define MPLLIBS_HANDLE_DO_FUN(f, arg_num) \
          template < \
            class A, \
            class E1, \
            class Monad, \
            BOOST_PP_ENUM_PARAMS(arg_num, class T) \
          > \
          struct \
            let_impl<A, E1, f<Monad, BOOST_PP_ENUM_PARAMS(arg_num, T)> > : \
            eval_match_let< \
              syntax<pair<let_do_w, _> >, \
              let_do_args< \
                A, \
                E1, \
                boost::mpl::vector<BOOST_PP_ENUM_PARAMS(arg_num, T)> \
              >, \
              syntax< \
                apply< \
                  BOOST_PP_CAT(instantiate, BOOST_PP_INC(arg_num))<f>, \
                  boost::mpl::push_front<let_do_w, Monad> \
                > \
              > \
            > \
          {}

        MPLLIBS_HANDLE_DO_FUN(do_, MPLLIBS_LIMIT_DO_SIZE);
        MPLLIBS_HANDLE_DO_FUN(do_c, MPLLIBS_LIMIT_DO_SIZE);

        #ifdef MPLLIBS_HANDE_DO_N
        #  error MPLLIBS_HANDLE_DO_N
        #endif
        #define MPLLIBS_HANDLE_DO_N(z, n, unused) \
          MPLLIBS_HANDLE_DO_FUN(BOOST_PP_CAT(do, n), n);

        BOOST_PP_REPEAT_FROM_TO(1, MPLLIBS_LIMIT_DO_SIZE, MPLLIBS_HANDLE_DO_N,~)

        #undef MPLLIBS_HANDLE_DO_N
        #undef MPLLIBS_HANDLE_DO_FUN
      }
    }
  }
}

#endif

