#ifndef MPLLIBS_METATEST_TO_STREAM_SEQUENCE_HPP
#define MPLLIBS_METATEST_TO_STREAM_SEQUENCE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/character_printer.hpp>
#include <mpllibs/metatest/to_stream.hpp>

#include <boost/mpl/aux_/range_c/tag.hpp>
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
#include <boost/mpl/next.hpp>
#include <boost/mpl/vector.hpp>

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

    #ifdef MPLLIBS_TO_STREAM_SEQUENCE
      #error MPLLIBS_TO_STREAM_SEQUENCE already defined
    #endif
    #define MPLLIBS_TO_STREAM_SEQUENCE(tag, name) \
      template <> \
      struct to_stream_impl<tag> \
      { \
        typedef to_stream_impl type; \
        \
        template <class Seq> \
        struct apply \
        { \
          typedef apply type; \
          \
          static std::ostream& run(std::ostream& o_) \
          { \
            return \
              mpllibs::metatest::to_stream_sequence_begin< \
                Seq, \
                typename boost::mpl::eval_if< \
                  typename boost::mpl::empty<Seq>::type, \
                  mpllibs::metatest::no_common_tag, \
                  mpllibs::metatest::common_tag<Seq> \
                >::type \
              >::run(o_ << "mpl::" #name); \
          } \
        }; \
      };
    
    #ifdef MPLLIBS_TO_STREAM_SEQUENCE_
      #error MPLLIBS_TO_STREAM_SEQUENCE_ already defined
    #endif
    #define MPLLIBS_TO_STREAM_SEQUENCE_(tag, name) \
      template <long N> \
      struct to_stream_impl<tag<N> > \
      { \
        typedef to_stream_impl type; \
        \
        template <class Seq> \
        struct apply \
        { \
          typedef apply type; \
          \
          static std::ostream& run(std::ostream& o_) \
          { \
            return \
              mpllibs::metatest::to_stream_sequence_begin< \
                Seq, \
                typename boost::mpl::eval_if< \
                  typename boost::mpl::empty<Seq>::type, \
                  mpllibs::metatest::no_common_tag, \
                  mpllibs::metatest::common_tag<Seq> \
                >::type \
              >::run(o_ << "mpl::" #name); \
          } \
        }; \
      };
    
    #if defined(BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)
      MPLLIBS_TO_STREAM_SEQUENCE(boost::mpl::aux::vector_tag, vector)
    #else
      MPLLIBS_TO_STREAM_SEQUENCE_(boost::mpl::aux::vector_tag, vector)
    #endif
    MPLLIBS_TO_STREAM_SEQUENCE(boost::mpl::aux::list_tag, list)
    MPLLIBS_TO_STREAM_SEQUENCE(boost::mpl::aux::half_open_range_tag, range)
    
    #undef MPLLIBS_TO_STREAM_SEQUENCE_
    #undef MPLLIBS_TO_STREAM_SEQUENCE

  }
}    

#endif

