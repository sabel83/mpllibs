#ifndef MPLLIBS_PARSER_SEQUENCE_H
#define MPLLIBS_PARSER_SEQUENCE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/unless_error.h>
#include <mpllibs/metaparse/accept.h>
#include <mpllibs/metaparse/get_result.h>
#include <mpllibs/metaparse/get_remaining.h>
#include <mpllibs/metaparse/get_position.h>

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
      template <class list_to_append, class new_result>
      struct append_accept :
        mpllibs::metaparse::accept<
          boost::mpl::push_back<
            list_to_append,
            typename mpllibs::metaparse::get_result<new_result>::type
          >,
          mpllibs::metaparse::get_remaining<new_result>,
          mpllibs::metaparse::get_position<new_result>
        >
      {};
    
      template <class accum, class s, class pos, class parser>
      struct apply_impl :
        mpllibs::metaparse::util::unless_error<
          boost::mpl::apply<parser, typename s::type, typename pos::type>,
          mpllibs::metaparse::impl::append_accept<
            typename accum::type,
            typename boost::mpl::apply<
              parser,
              typename s::type,
              typename pos::type
            >::type
          >
        >
      {};
    
      struct apply_parser
      {
        template <class state, class parser>
        struct apply :
          mpllibs::metaparse::util::unless_error<
            state,
            mpllibs::metaparse::impl::apply_impl<
              mpllibs::metaparse::get_result<state>,
              mpllibs::metaparse::get_remaining<state>,
              mpllibs::metaparse::get_position<state>,
              parser
            >
          >
        {};
      };
    
      template <class ps, class s, class pos>
      struct sequence_impl :
        boost::mpl::fold<
          ps,
          mpllibs::metaparse::accept<boost::mpl::deque<>, s, pos>,
          mpllibs::metaparse::impl::apply_parser
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
        BOOST_PP_ENUM_PARAMS(n, class p) \
        BOOST_PP_COMMA_IF(n) \
        class mock = int \
      > \
      struct sequence##n \
      { \
        template <class s, class pos> \
        struct apply : \
          mpllibs::metaparse::impl::sequence_impl< \
            boost::mpl::vector<BOOST_PP_ENUM_PARAMS(n, p)>, \
            s, \
            pos \
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
        class p,
        mpllibs::metaparse::impl::sequence_no_argument
      ),
      class mock = int
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
      template <BOOST_PP_ENUM_PARAMS(n, class p)> \
      struct sequence< \
        BOOST_PP_ENUM_PARAMS(n, p) \
        BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT( \
          BOOST_PP_SUB(SEQUENCE_MAX_ARGUMENT, n), \
          SEQUENCE_UNUSED_PARAM, \
          ~ \
        ) \
      > : \
        mpllibs::metaparse::sequence##n<BOOST_PP_ENUM_PARAMS(n, p)> \
      {};
    
    BOOST_PP_REPEAT(SEQUENCE_MAX_ARGUMENT, SEQUENCE_N, ~)
    
    #undef SEQUENCE_N
    #undef SEQUENCE_UNUSED_PARAM
  }
}

#endif

