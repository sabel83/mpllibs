#ifndef MPLLIBS_METAPARSE_NTH_OF_HPP
#define MPLLIBS_METAPARSE_NTH_OF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/sequence.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/fail.hpp>

#include <mpllibs/metaparse/util/int_to_string.hpp>
#include <mpllibs/metaparse/util/join_string.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/string.hpp>

#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    namespace errors
    {
      template <int From, int To, int N>
      struct index_out_of_range :
        mpllibs::metaparse::util::join_string<
          boost::mpl::vector<
            boost::mpl::string<'inde','x ('>,
            mpllibs::metaparse::util::int_to_string::apply<
              boost::mpl::int_<N>
            >,
            boost::mpl::string<') ou','t of',' ran','ge ','['>,
            mpllibs::metaparse::util::int_to_string::apply<
              boost::mpl::int_<From>
            >,
            boost::mpl::string<'-'>,
            mpllibs::metaparse::util::int_to_string::apply<
              boost::mpl::int_<To>
            >,
            boost::mpl::string<']'>
          >
        >
      {};
    }
  
    namespace impl
    {
      struct skip_seq
      {
      private:
        template <class ParsingResult, class NewResultValue>
        struct change_result :
          boost::mpl::apply_wrap2<
            mpllibs::metaparse::return_<NewResultValue>,
            typename mpllibs::metaparse::get_remaining<ParsingResult>::type,
            typename mpllibs::metaparse::get_position<ParsingResult>::type
          >
        {};
      
        template <class Result, class P>
        struct apply_unchecked :
          boost::mpl::eval_if<
            typename mpllibs::metaparse::is_error<
              boost::mpl::apply<
                P,
                typename mpllibs::metaparse::get_remaining<Result>::type,
                typename mpllibs::metaparse::get_position<Result>::type
              >
            >::type,
            boost::mpl::apply<
              P,
              typename mpllibs::metaparse::get_remaining<Result>::type,
              typename mpllibs::metaparse::get_position<Result>::type
            >,
            change_result<
              boost::mpl::apply<
                P,
                typename mpllibs::metaparse::get_remaining<Result>::type,
                typename mpllibs::metaparse::get_position<Result>::type
              >,
              typename mpllibs::metaparse::get_result<Result>::type
            >
          >
        {};
        
      public:
        template <class Result, class P>
        struct apply :
          boost::mpl::eval_if<
            mpllibs::metaparse::is_error<Result>,
            Result,
            apply_unchecked<Result, P>
          >
        {};
      };
      
      template <int N, class Seq>
      struct nth_of_c_impl
      {
      private:
        template <class NextResult>
        struct apply_unchecked :
          boost::mpl::apply_wrap2<
            nth_of_c_impl<
              N - 1,
              typename boost::mpl::pop_front<Seq>::type
            >,
            typename mpllibs::metaparse::get_remaining<NextResult>::type,
            typename mpllibs::metaparse::get_position<NextResult>::type
          >
        {};
      public:
        typedef nth_of_c_impl type;
        
        template <class S, class Pos>
        struct apply :
          boost::mpl::eval_if<
            typename mpllibs::metaparse::is_error<
              boost::mpl::apply<typename boost::mpl::front<Seq>::type, S, Pos>
            >::type,
            boost::mpl::apply<typename boost::mpl::front<Seq>::type, S, Pos>,
            apply_unchecked<
              boost::mpl::apply<typename boost::mpl::front<Seq>::type, S, Pos>
            >
          >
        {};
      };
      
      template <class Seq>
      struct nth_of_c_impl<0, Seq>
      {
        typedef nth_of_c_impl type;
        
        template <class S, class Pos>
        struct apply :
          boost::mpl::fold<
            typename boost::mpl::pop_front<Seq>::type,
            typename boost::mpl::apply<
              typename boost::mpl::front<Seq>::type,
              S,
              Pos
            >::type,
            skip_seq
          >
        {};
      };
    }
  
    #ifdef MPLLIBS_NTH_OF_CASE
      #error MPLLIBS_NTH_OF_CASE already defined
    #endif
    #define MPLLIBS_NTH_OF_CASE(z, n, unused) \
      template < \
        int K BOOST_PP_COMMA_IF(n) \
        BOOST_PP_ENUM_PARAMS(n, class P) \
      > \
      struct nth_of_c##n : \
        boost::mpl::if_< \
          boost::mpl::bool_<(0 <= K && K < n)>, \
          mpllibs::metaparse::impl::nth_of_c_impl< \
            K, \
            boost::mpl::list<BOOST_PP_ENUM_PARAMS(n, P)> \
          >, \
          fail< \
            mpllibs::metaparse::errors::index_out_of_range<0, n - 1, K> \
          > \
        >::type \
      {};
    
    BOOST_PP_REPEAT(MPLLIBS_SEQUENCE_MAX_ARGUMENT, MPLLIBS_NTH_OF_CASE, ~)
    
    #undef MPLLIBS_NTH_OF_CASE
    
    




    template <
      int N,
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_SEQUENCE_MAX_ARGUMENT,
        class P,
        boost::mpl::na
      )
    >
    struct nth_of_c;


    #ifdef MPLLIBS_SEQUENCE_UNUSED_PARAM
      #error MPLLIBS_SEQUENCE_UNUSED_PARAM already defined
    #endif
    #define MPLLIBS_SEQUENCE_UNUSED_PARAM(z, n, unused) \
      BOOST_PP_COMMA_IF(n) boost::mpl::na
    
    #ifdef MPLLIBS_NTH_OF_N
      #error MPLLIBS_NTH_OF_N already defined
    #endif
    #define MPLLIBS_NTH_OF_N(z, n, unused) \
      template <int K BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_PARAMS(n, class P)> \
      struct nth_of_c< \
        K, \
        BOOST_PP_ENUM_PARAMS(n, P) \
        BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT( \
          BOOST_PP_SUB(MPLLIBS_SEQUENCE_MAX_ARGUMENT, n), \
          MPLLIBS_SEQUENCE_UNUSED_PARAM, \
          ~ \
        ) \
      > : \
        nth_of_c##n< \
          K BOOST_PP_COMMA_IF(n) \
          BOOST_PP_ENUM_PARAMS(n, P) \
        > \
      {};
    
    BOOST_PP_REPEAT(MPLLIBS_SEQUENCE_MAX_ARGUMENT, MPLLIBS_NTH_OF_N, ~)
    
    #undef MPLLIBS_NTH_OF_N
    #undef MPLLIBS_SEQUENCE_UNUSED_PARAM
    
    
    
    
    
    template <
      class K,
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_SEQUENCE_MAX_ARGUMENT,
        class P,
        boost::mpl::na
      )
    >
    struct nth_of :
      nth_of_c<
        K::type::value,
        BOOST_PP_ENUM_PARAMS(MPLLIBS_SEQUENCE_MAX_ARGUMENT, P)
      >
    {};
  }
}

#endif

