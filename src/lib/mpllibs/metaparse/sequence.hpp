#ifndef MPLLIBS_PARSER_SEQUENCE_H
#define MPLLIBS_PARSER_SEQUENCE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/unless_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>
#include <mpllibs/metaparse/get_position.hpp>
#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/transform.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/fold.hpp>

#include <boost/preprocessor/repetition.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace impl
    {
      template <class ListToAppend>
      struct do_append
      {
        template <class Item>
        struct apply :
          boost::mpl::push_back<ListToAppend, typename Item::type>
        {};
      };
    
      template <class Accum, class S, class Pos, class Parser>
      struct apply_impl :
        boost::mpl::apply<
          mpllibs::metaparse::transform<
            Parser,do_append<typename Accum::type>
          >,
          typename S::type,
          typename Pos::type
        >
      {};
    
      struct apply_parser
      {
        template <class State, class Parser>
        struct apply :
          mpllibs::metaparse::util::unless_error<
            State,
            apply_impl<
              mpllibs::metaparse::get_result<State>,
              mpllibs::metaparse::get_remaining<State>,
              mpllibs::metaparse::get_position<State>,
              Parser
            >
          >
        {};
      };
      
      template <class Ps, class S, class Pos>
      struct sequence_impl :
        boost::mpl::fold<
          Ps,
          typename boost::mpl::apply<
            mpllibs::metaparse::return_<boost::mpl::deque<> >,
            S,
            Pos
          >::type,
          apply_parser
        >
      {};
    }
  
    #ifndef SEQUENCE_MAX_ARGUMENT
      #define SEQUENCE_MAX_ARGUMENT 5
    #endif

    #ifdef SEQUENCE_CASE
      #error SEQUENCE_CASE already defined
    #endif
    // We need a mock argument to make the 0 case compile
    #define SEQUENCE_CASE(z, n, unused) \
      template < \
        BOOST_PP_ENUM_PARAMS(n, class P) \
        BOOST_PP_COMMA_IF(n) \
        class Mock = int \
      > \
      struct sequence##n \
      { \
        template <class S, class Pos> \
        struct apply : \
          mpllibs::metaparse::impl::sequence_impl< \
            boost::mpl::vector<BOOST_PP_ENUM_PARAMS(n, P)>, \
            S, \
            Pos \
          > \
        {}; \
      };
    
    BOOST_PP_REPEAT(SEQUENCE_MAX_ARGUMENT, SEQUENCE_CASE, ~)
    
    #undef SEQUENCE_CASE
    




    namespace impl
    {
      struct sequence_no_argument;
    }

    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        SEQUENCE_MAX_ARGUMENT,
        class P,
        mpllibs::metaparse::impl::sequence_no_argument
      ),
      class Mock = int
    >
    struct sequence;


    #ifdef SEQUENCE_UNUSED_PARAM
      #error SEQUENCE_UNUSED_PARAM already defined
    #endif
    #define SEQUENCE_UNUSED_PARAM(z, n, unused) \
      BOOST_PP_COMMA_IF(n) mpllibs::metaparse::impl::sequence_no_argument
    
    #ifdef SEQUENCE_N
      #error SEQUENCE_N already defined
    #endif
    #define SEQUENCE_N(z, n, unused) \
      template <BOOST_PP_ENUM_PARAMS(n, class P)> \
      struct sequence< \
        BOOST_PP_ENUM_PARAMS(n, P) \
        BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT( \
          BOOST_PP_SUB(SEQUENCE_MAX_ARGUMENT, n), \
          SEQUENCE_UNUSED_PARAM, \
          ~ \
        ) \
      > : \
        sequence##n<BOOST_PP_ENUM_PARAMS(n, P)> \
      {};
    
    BOOST_PP_REPEAT(SEQUENCE_MAX_ARGUMENT, SEQUENCE_N, ~)
    
    #undef SEQUENCE_N
    #undef SEQUENCE_UNUSED_PARAM
  }
}

#endif

