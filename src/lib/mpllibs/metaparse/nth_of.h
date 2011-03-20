#ifndef MPLLIBS_PARSER_NTH_OF_H
#define MPLLIBS_PARSER_NTH_OF_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/sequence.h>
#include <mpllibs/metaparse/transform.h>

#include <boost/mpl/at.hpp>
#include <boost/mpl/apply.hpp>

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
      template <int n>
      struct get_nth
      {
        template <class seq>
        struct apply : boost::mpl::at_c<typename seq::type, n> {};
      };
      
      template <int n, class seq>
      struct nth_of_c_impl :
        mpllibs::metaparse::transform<seq,mpllibs::metaparse::impl::get_nth<n> >
      {};
    }
  
    #ifdef NTH_OF_CASE
      #error NTH_OF_CASE already defined
    #endif
    #define NTH_OF_CASE(z, n, unused) \
      template < \
        int k BOOST_PP_COMMA_IF(n) \
        BOOST_PP_ENUM_PARAMS(n, class p) \
      > \
      struct nth_of_c##n : \
        mpllibs::metaparse::impl::nth_of_c_impl< \
          k, \
          mpllibs::metaparse::sequence<BOOST_PP_ENUM_PARAMS(n, p)> \
        > \
      {};
    
    BOOST_PP_REPEAT(SEQUENCE_MAX_ARGUMENT, NTH_OF_CASE, ~)
    
    #undef NTH_OF_CASE
    
    




    template <
      int n,
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        SEQUENCE_MAX_ARGUMENT,
        class p,
        mpllibs::metaparse::impl::sequence_no_argument
      )
    >
    struct nth_of_c;


    #ifdef SEQUENCE_UNUSED_PARAM
      #error SEQUENCE_UNUSED_PARAM already defined
    #endif
    #define SEQUENCE_UNUSED_PARAM(z, n, unused) \
      BOOST_PP_COMMA_IF(n) mpllibs::metaparse::impl::sequence_no_argument
    
    #ifdef NTH_OF_N
      #error NTH_OF_N already defined
    #endif
    #define NTH_OF_N(z, n, unused) \
      template <int k BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_PARAMS(n, class p)> \
      struct nth_of_c< \
        k, \
        BOOST_PP_ENUM_PARAMS(n, p) \
        BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT( \
          BOOST_PP_SUB(SEQUENCE_MAX_ARGUMENT, n), \
          SEQUENCE_UNUSED_PARAM, \
          ~ \
        ) \
      > : \
        mpllibs::metaparse::nth_of_c##n< \
          k BOOST_PP_COMMA_IF(n) \
          BOOST_PP_ENUM_PARAMS(n, p) \
        > \
      {};
    
    BOOST_PP_REPEAT(SEQUENCE_MAX_ARGUMENT, NTH_OF_N, ~)
    
    #undef NTH_OF_N
    #undef SEQUENCE_UNUSED_PARAM
    
    
    
    
    
    template <
      class k,
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        SEQUENCE_MAX_ARGUMENT,
        class p,
        mpllibs::metaparse::impl::sequence_no_argument
      )
    >
    struct nth_of :
      nth_of_c<k::type::value, BOOST_PP_ENUM_PARAMS(SEQUENCE_MAX_ARGUMENT, p)>
    {};
  }
}

#endif

