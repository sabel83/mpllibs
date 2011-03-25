#ifndef MPLLIBS_PARSER_NTH_OF_H
#define MPLLIBS_PARSER_NTH_OF_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/sequence.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/return.h>
#include <mpllibs/metaparse/fail.h>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/fold.hpp>

#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    namespace errors
    {
      template <int from, int to, int n>
      struct index_out_of_range
      {
        typedef index_out_of_range type;
      };
    }
  
    namespace impl
    {
      struct skip_seq
      {
      private:
        template <class parsingResult, class newResultValue>
        struct change_result :
          boost::mpl::apply<
            mpllibs::metaparse::return_<newResultValue>,
            typename mpllibs::metaparse::get_remaining<parsingResult>::type,
            typename mpllibs::metaparse::get_position<parsingResult>::type
          >
        {};
      
        template <class result, class p>
        struct apply_unchecked :
          boost::mpl::eval_if<
            typename mpllibs::metaparse::is_error<
              boost::mpl::apply<
                p,
                typename mpllibs::metaparse::get_remaining<result>::type,
                typename mpllibs::metaparse::get_position<result>::type
              >
            >::type,
            boost::mpl::apply<
              p,
              typename mpllibs::metaparse::get_remaining<result>::type,
              typename mpllibs::metaparse::get_position<result>::type
            >,
            change_result<
              boost::mpl::apply<
                p,
                typename mpllibs::metaparse::get_remaining<result>::type,
                typename mpllibs::metaparse::get_position<result>::type
              >,
              typename mpllibs::metaparse::get_result<result>::type
            >
          >
        {};
        
      public:
        template <class result, class p>
        struct apply :
          boost::mpl::eval_if<
            mpllibs::metaparse::is_error<result>,
            result,
            apply_unchecked<result, p>
          >
        {};
      };
      
      template <int n, class seq>
      struct nth_of_c_impl
      {
      private:
        template <class nextResult>
        struct apply_unchecked :
          boost::mpl::apply<
            mpllibs::metaparse::impl::nth_of_c_impl<
              n - 1,
              typename boost::mpl::pop_front<seq>::type
            >,
            typename mpllibs::metaparse::get_remaining<nextResult>::type,
            typename mpllibs::metaparse::get_position<nextResult>::type
          >
        {};
      public:
        template <class s, class pos>
        struct apply :
          boost::mpl::eval_if<
            typename mpllibs::metaparse::is_error<
              boost::mpl::apply<typename boost::mpl::front<seq>::type, s, pos>
            >::type,
            boost::mpl::apply<typename boost::mpl::front<seq>::type, s, pos>,
            apply_unchecked<
              boost::mpl::apply<typename boost::mpl::front<seq>::type, s, pos>
            >
          >
        {};
      };
      
      template <class seq>
      struct nth_of_c_impl<0, seq>
      {
        template <class s, class pos>
        struct apply :
          boost::mpl::fold<
            typename boost::mpl::pop_front<seq>::type,
            typename boost::mpl::apply<
              typename boost::mpl::front<seq>::type,
              s,
              pos
            >::type,
            mpllibs::metaparse::impl::skip_seq
          >
        {};
      };
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
        boost::mpl::if_< \
          boost::mpl::bool_<(0 <= k && k < n)>, \
          mpllibs::metaparse::impl::nth_of_c_impl< \
            k, \
            boost::mpl::list<BOOST_PP_ENUM_PARAMS(n, p)> \
          >, \
          mpllibs::metaparse::fail< \
            mpllibs::metaparse::errors::index_out_of_range<0, n - 1, k> \
          > \
        >::type \
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
  
  namespace metatest
  {
    template <class>
    struct to_stream;

    template <int from, int to, int n>
    struct to_stream<
      mpllibs::metaparse::errors::index_out_of_range<from, to, n>
    >
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return o_
          << "Index (" << n << ") out of range [" << from << ", "<< to << "]";
      }
    };
  }
}

#endif

