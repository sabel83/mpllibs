#ifndef MPLLIBS_METATEST_TO_STREAM_SEQUENCE_HPP
#define MPLLIBS_METATEST_TO_STREAM_SEQUENCE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011-2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/character_printer.hpp>
#include <mpllibs/metatest/to_stream.hpp>

#include <boost/mpl/begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/set.hpp>
#include <boost/mpl/set_c.hpp>
#include <boost/mpl/map.hpp>

#include <boost/type_traits/is_same.hpp>

namespace mpllibs
{
  namespace metatest
  {
    struct to_stream_nothing
    {
      typedef to_stream_nothing type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return o_;
      }
    };

    template <class I, class End>
    struct to_stream_sequence_impl;

    template <class I, class End>
    struct to_stream_sequence :
      boost::mpl::if_<
        boost::is_same<I, End>,
        to_stream_nothing,
        to_stream_sequence_impl<I, End>
      >::type
    {};
    
    template <class I, class End>
    struct to_stream_sequence_impl
    {
      typedef to_stream_sequence_impl type;
      
      static std::ostream& run(std::ostream& o_)
      {
        using boost::mpl::next;
        using boost::mpl::deref;
        using boost::is_same;
        
        typedef typename next<I>::type i_next;
        typedef typename deref<I>::type deref_i;
        const bool is_at_end = is_same<i_next, End>::type::value;
        
        to_stream<deref_i>::run(o_);
        o_ << (is_at_end ? "" : ", ");
        to_stream_sequence<i_next, End>::run(o_);
        return o_;
      }
    };
    

    template <class I, class End>
    struct to_stream_sequence_values_impl;

    template <class I, class End>
    struct to_stream_sequence_values :
      boost::mpl::if_<
        boost::is_same<I, End>,
        to_stream_nothing,
        to_stream_sequence_values_impl<I, End>
      >::type
    {};
    
    template <class I, class End>
    struct to_stream_sequence_values_impl
    {
      typedef to_stream_sequence_values_impl type;
      
      static std::ostream& run(std::ostream& o_)
      {
        using boost::mpl::next;
        using boost::mpl::deref;
        using boost::is_same;
        
        typedef typename next<I>::type i_next;
        typedef typename deref<I>::type deref_i;
        const bool is_at_end = is_same<i_next, End>::type::value;
        
        o_ << deref_i::value << (is_at_end ? "" : ", ");
        to_stream_sequence_values<i_next, End>::run(o_);
        return o_;
      }
    };

    struct no_common_tag
    {
      typedef no_common_tag type;
    };
    
    // I can't use a lambda expression, because is_same is not lazy
    struct common_tag_compare
    {
      typedef common_tag_compare type;
      
      template <class A, class B>
      struct apply :
        boost::mpl::if_<
          boost::is_same<A, typename boost::mpl::tag<B>::type>,
          A,
          no_common_tag
        >
      {};
    };
    
    template <class Seq>
    struct common_tag :
      boost::mpl::fold<
        Seq,
        typename boost::mpl::tag<typename boost::mpl::front<Seq>::type>::type,
        common_tag_compare
      >
    {};
    
    template <class Seq, class CommonTag>
    struct to_stream_sequence_begin
    {
      typedef to_stream_sequence_begin type;
      
      static std::ostream& run(std::ostream& o_)
      {
        using boost::mpl::begin;
        using boost::mpl::end;
        
        typedef typename begin<Seq>::type b;
        typedef typename end<Seq>::type e;
        
        o_  << "<";
        to_stream_sequence<b, e>::run(o_);
        return o_ << ">";
      }
    };
    
    // pre-condition: !empty<Seq>
    template <class Seq>
    struct to_stream_sequence_begin<Seq, boost::mpl::integral_c_tag>
    {
      typedef to_stream_sequence_begin type;
      
      static std::ostream& run(std::ostream& o_)
      {
        using boost::mpl::begin;
        using boost::mpl::end;
        using boost::mpl::front;
        
        typedef typename front<Seq>::type::value_type v_type;
        
        o_ << "_c<";
        mpllibs::metatest::to_stream<v_type>::run(o_);
        o_ << ", ";
        
        if (boost::is_same<char, v_type>::type::value)
        {
          o_ << '\"';
          boost::mpl::for_each<Seq>(character_printer(o_));
          o_ << '\"';
        }
        else
        {
          typedef typename begin<Seq>::type b;
          typedef typename end<Seq>::type e;
          
          to_stream_sequence_values<b, e>::run(o_);
        }
          
        return o_ << ">";
      }
    };

    template <class S, class Name>
    struct to_stream_seq
    {
      typedef to_stream_seq type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return
          to_stream_sequence_begin<
            S,
            typename boost::mpl::eval_if<
              typename boost::mpl::empty<S>::type,
              no_common_tag,
              common_tag<S>
            >::type
          >::run(o_ << "mpl::" << Name::run());
      }
    };

    namespace util
    {
      // Use these classes instead of TMP strings for simplicity
      #ifdef MPLLIBS_DEF_NAME
        #error MPLLIBS_DEF_NAME already defined
      #endif
      #define MPLLIBS_DEF_NAME(s) \
        struct name_##s \
        { \
          typedef name_##s type; \
          static const char* run() \
          { \
            return #s; \
          } \
        };

      MPLLIBS_DEF_NAME(list)
      MPLLIBS_DEF_NAME(vector)
      MPLLIBS_DEF_NAME(set)
      MPLLIBS_DEF_NAME(map)
      MPLLIBS_DEF_NAME(deque)

      #undef MPLLIBS_DEF_NAME
    }

    #ifdef MPLLIBS_DEF_SEQ_C
      #error MPLLIBS_DEF_SEQ_C already defined
    #endif
    #define MPLLIBS_DEF_SEQ_C(seq, limit) \
      template <class T, BOOST_PP_ENUM_PARAMS(limit, long N)> \
      struct to_stream< \
        BOOST_PP_CAT(boost::mpl::seq, _c)<T, BOOST_PP_ENUM_PARAMS(limit, N)> \
      > : \
        to_stream_seq< \
          BOOST_PP_CAT(boost::mpl::seq, _c)< \
            T, \
            BOOST_PP_ENUM_PARAMS(limit, N) \
          >, \
          BOOST_PP_CAT(mpllibs::metatest::util::name_, seq) \
        > \
      {};

    #ifdef MPLLIBS_DEF_SEQ
      #error MPLLIBS_DEF_SEQ already defined
    #endif
    #define MPLLIBS_DEF_SEQ(seq, limit) \
      template <BOOST_PP_ENUM_PARAMS(limit, class T)> \
      struct to_stream<boost::mpl::seq<BOOST_PP_ENUM_PARAMS(limit, T)> > : \
        to_stream_seq< \
          boost::mpl::seq<BOOST_PP_ENUM_PARAMS(limit, T)>, \
          BOOST_PP_CAT(mpllibs::metatest::util::name_, seq) \
        > \
      {};

    #ifdef MPLLIBS_DEF_SEQ_N_ITER
      #error MPLLIBS_DEF_SEQ_N_ITER already defined
    #endif
    #define MPLLIBS_DEF_SEQ_N_ITER(z, n, seq) \
      template <BOOST_PP_ENUM_PARAMS(n, class T)> \
      struct to_stream< \
        BOOST_PP_CAT(boost::mpl::seq, n)<BOOST_PP_ENUM_PARAMS(n, T)> \
      > : \
        to_stream_seq< \
          BOOST_PP_CAT(boost::mpl::seq, n)<BOOST_PP_ENUM_PARAMS(n, T)>, \
          BOOST_PP_CAT(mpllibs::metatest::util::name_, seq) \
        > \
      {};

    #ifdef MPLLIBS_DEF_SEQ_N
      #error MPLLIBS_DEF_SEQ_N already defined
    #endif
    #define MPLLIBS_DEF_SEQ_N(seq, limit) \
      template <class Dummy> \
      struct to_stream<BOOST_PP_CAT(boost::mpl::seq, 0)<Dummy> > : \
        to_stream_seq< \
          BOOST_PP_CAT(boost::mpl::seq, 0)<Dummy>, \
          BOOST_PP_CAT(mpllibs::metatest::util::name_, seq) \
        > \
      {};\
      \
      BOOST_PP_REPEAT_FROM_TO( \
        1, \
        limit, \
        MPLLIBS_DEF_SEQ_N_ITER, \
        seq \
      )

    MPLLIBS_DEF_SEQ(list, BOOST_MPL_LIMIT_LIST_SIZE)
    MPLLIBS_DEF_SEQ_C(list, BOOST_MPL_LIMIT_LIST_SIZE)
    MPLLIBS_DEF_SEQ_N(list, BOOST_MPL_LIMIT_VECTOR_SIZE)
    MPLLIBS_DEF_SEQ(vector, BOOST_MPL_LIMIT_VECTOR_SIZE)
    MPLLIBS_DEF_SEQ_C(vector, BOOST_MPL_LIMIT_VECTOR_SIZE)
    MPLLIBS_DEF_SEQ_N(vector, BOOST_MPL_LIMIT_VECTOR_SIZE)
    MPLLIBS_DEF_SEQ(deque, BOOST_MPL_LIMIT_VECTOR_SIZE)
    MPLLIBS_DEF_SEQ(set, BOOST_MPL_LIMIT_SET_SIZE)
    MPLLIBS_DEF_SEQ_C(set, BOOST_MPL_LIMIT_SET_SIZE)
    MPLLIBS_DEF_SEQ_N(set, BOOST_MPL_LIMIT_SET_SIZE)
    MPLLIBS_DEF_SEQ(map, BOOST_MPL_LIMIT_MAP_SIZE)
    MPLLIBS_DEF_SEQ_N(map, BOOST_MPL_LIMIT_MAP_SIZE)

    #undef MPLLIBS_DEF_SEQ_N_ITER
    #undef MPLLIBS_DEF_SEQ_N
    #undef MPLLIBS_DEF_SEQ
    #undef MPLLIBS_DEF_SEQ_C
  }
}    

#endif

