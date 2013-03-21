#ifndef MPLLIBS_METAPARSE_SEQUENCE_HPP
#define MPLLIBS_METAPARSE_SEQUENCE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/unless_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>
#include <mpllibs/metaparse/get_position.hpp>
#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/transform.hpp>

#include <boost/mpl/apply_wrap.hpp>
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
      struct apply_parser
      {
      private:
        template <class ListToAppend>
        struct do_append
        {
          template <class Item>
          struct apply :
            boost::mpl::push_back<ListToAppend, typename Item::type>
          {};
        };

        template <class Accum, class S, class Pos, class Parser>
        struct apply_unchecked :
          boost::mpl::apply_wrap2<
            mpllibs::metaparse::transform<
              Parser,do_append<typename Accum::type>
            >,
            typename S::type,
            typename Pos::type
          >
        {};
        
      public:
        template <class State, class Parser>
        struct apply :
          mpllibs::metaparse::unless_error<
            State,
            apply_unchecked<
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
          typename boost::mpl::apply_wrap2<
            mpllibs::metaparse::return_<boost::mpl::deque<> >,
            S,
            Pos
          >::type,
          apply_parser
        >
      {};
    }
  
    #ifndef MPLLIBS_SEQUENCE_MAX_ARGUMENT
      #define MPLLIBS_SEQUENCE_MAX_ARGUMENT 5
    #endif

    #ifdef MPLLIBS_SEQUENCE_CASE
      #error MPLLIBS_SEQUENCE_CASE already defined
    #endif
    // We need a mock argument to make the 0 case compile
    #define MPLLIBS_SEQUENCE_CASE(z, n, unused) \
      template < \
        BOOST_PP_ENUM_PARAMS(n, class P) \
        BOOST_PP_COMMA_IF(n) \
        class Mock = int \
      > \
      struct sequence##n \
      { \
        typedef sequence##n type; \
        \
        template <class S, class Pos> \
        struct apply : \
          mpllibs::metaparse::impl::sequence_impl< \
            boost::mpl::vector<BOOST_PP_ENUM_PARAMS(n, P)>, \
            S, \
            Pos \
          > \
        {}; \
      };
    
    BOOST_PP_REPEAT(MPLLIBS_SEQUENCE_MAX_ARGUMENT, MPLLIBS_SEQUENCE_CASE, ~)
    
    #undef MPLLIBS_SEQUENCE_CASE
    





    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_SEQUENCE_MAX_ARGUMENT,
        class P,
        boost::mpl::na
      ),
      class Mock = int
    >
    struct sequence;


    #ifdef MPLLIBS_SEQUENCE_UNUSED_PARAM
      #error MPLLIBS_SEQUENCE_UNUSED_PARAM already defined
    #endif
    #define MPLLIBS_SEQUENCE_UNUSED_PARAM(z, n, unused) \
      BOOST_PP_COMMA_IF(n) boost::mpl::na
    
    #ifdef MPLLIBS_SEQUENCE_N
      #error MPLLIBS_SEQUENCE_N already defined
    #endif
    #define MPLLIBS_SEQUENCE_N(z, n, unused) \
      template <BOOST_PP_ENUM_PARAMS(n, class P)> \
      struct sequence< \
        BOOST_PP_ENUM_PARAMS(n, P) \
        BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT( \
          BOOST_PP_SUB(MPLLIBS_SEQUENCE_MAX_ARGUMENT, n), \
          MPLLIBS_SEQUENCE_UNUSED_PARAM, \
          ~ \
        ) \
      > : sequence##n<BOOST_PP_ENUM_PARAMS(n, P)> \
      {};
    
    BOOST_PP_REPEAT(MPLLIBS_SEQUENCE_MAX_ARGUMENT, MPLLIBS_SEQUENCE_N, ~)
    
    #undef MPLLIBS_SEQUENCE_N
    #undef MPLLIBS_SEQUENCE_UNUSED_PARAM
  }
}

#endif

