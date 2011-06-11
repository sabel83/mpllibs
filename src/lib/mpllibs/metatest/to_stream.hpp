#ifndef MPLLIBS_METATEST_TO_STREAM_HPP
#define MPLLIBS_METATEST_TO_STREAM_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/accumulate.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/aux_/range_c/tag.hpp>
#include <boost/mpl/base.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/bitand.hpp>
#include <boost/mpl/bitwise.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/copy_if.hpp>
#include <boost/mpl/count.hpp>
#include <boost/mpl/count_if.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/empty_sequence.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/erase.hpp>
#include <boost/mpl/erase_key.hpp>
#include <boost/mpl/filter_view.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/greater_equal.hpp>
#include <boost/mpl/greater.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/inherit.hpp>
#include <boost/mpl/inherit_linearly.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/insert_range.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/iterator_category.hpp>
#include <boost/mpl/key_type.hpp>
#include <boost/mpl/less_equal.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/lower_bound.hpp>
#include <boost/mpl/max_element.hpp>
#include <boost/mpl/min_element.hpp>
#include <boost/mpl/modulus.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/not_equal_to.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/order.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/partition.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/remove.hpp>
#include <boost/mpl/remove_if.hpp>
#include <boost/mpl/replace.hpp>
#include <boost/mpl/replace_if.hpp>
#include <boost/mpl/reverse.hpp>
#include <boost/mpl/reverse_iter_fold.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/mpl/sort.hpp>
#include <boost/mpl/string.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/transform_view.hpp>
#include <boost/mpl/unique.hpp>
#include <boost/mpl/unpack_args.hpp>
#include <boost/mpl/upper_bound.hpp>
#include <boost/mpl/value_type.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/void.hpp>
#include <boost/mpl/zip_view.hpp>

#include <boost/type_traits/is_same.hpp>

#include <iostream>

#include <cassert>

namespace mpllibs
{
  namespace metatest
  {
    template <class T>
    struct to_stream_impl
    {
      template <class V>
      struct apply
      {
        typedef apply type;
      
        static std::ostream& run(std::ostream& o_)
        {
          // I can't use typeid, because it breaks for non-defined types
          return o_ << "???";
        }
      };
    };
    
    template <class T>
    struct to_stream :
      boost::mpl::apply<to_stream_impl<typename boost::mpl::tag<T>::type>, T>
    {};
    
    template <class T>
    struct to_stream<T*>
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return to_stream<T>::run(o_) << "*";
      }
    };

    template <class T>
    struct to_stream<T[]>
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return to_stream<T>::run(o_) << "[]";
      }
    };

    template <class T>
    struct to_stream<T&>
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return to_stream<T>::run(o_) << "&";
      }
    };

    template <class T>
    struct to_stream<const T>
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return to_stream<T>::run(o_ << "const ");
      }
    };

    template <class T>
    struct to_stream<T* const>
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return to_stream<T>::run(o_) << "* const";
      }
    };



    template <class ValueType, ValueType Value>
    struct to_stream_integral_constant
    {
      typedef to_stream_integral_constant type;
        
      static std::ostream& run(std::ostream& o_)
      {
        to_stream<ValueType>::run(o_ << "integral_c<");
        return o_ << ", " << Value << ">";
      }
    };

    template <bool Value>
    struct to_stream_integral_constant<bool, Value>
    {
      typedef to_stream_integral_constant type;
        
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << (Value ? "true_" : "false_");
      }
    };

    template <int Value>
    struct to_stream_integral_constant<int, Value>
    {
      typedef to_stream_integral_constant type;
        
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << "int_<" << Value << ">";
      }
    };

    template <long Value>
    struct to_stream_integral_constant<long, Value>
    {
      typedef to_stream_integral_constant type;
        
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << "long_<" << Value << ">";
      }
    };
    
    class character_printer
    {
    public:
      character_printer(std::ostream& o_) : _o(o_) {}
    
      void operator()(unsigned char c_)
      {
        switch (c_)
        {
        case '\0': _o << "\\0"; break;
        case '\n': _o << "\\n"; break;
        case '\t': _o << "\\t"; break;
        case '\b': _o << "\\b"; break;
        case '\v': _o << "\\v"; break;
        case '\r': _o << "\\r"; break;
        case '\f': _o << "\\f"; break;
        case '\a': _o << "\\a"; break;
        case '\\': _o << "\\\\"; break;
        case '\?': _o << "\\?"; break;
        case '\'': _o << "\\\'"; break;
        case '\"': _o << "\\\""; break;
        default:
          if (c_ > 31 && c_ != 127)
          {
            _o << c_;
          }
          else
          {
            using std::ios_base;
            using std::ios;
            
            _o << "\\x";
            
            const ios_base::fmtflags f = _o.flags();
            _o.flags(ios::hex);
            _o << (c_ & 0xf0) << (c_ & 0x0f);
            _o.flags(f);
          }
        }
      }
    private:
      std::ostream& _o;
    };

    template <char Value>
    struct to_stream_integral_constant<char, Value>
    {
      typedef to_stream_integral_constant type;
        
      static std::ostream& run(std::ostream& o_)
      {
        assert(sizeof(char) == 1);

        o_ << "char_<\'";
        character_printer(o_).operator()(Value);
        return o_ << "\'>";
      }
    };

    template <>
    struct to_stream_impl<boost::mpl::integral_c_tag>
    {
      template <class T>
      struct apply :
        mpllibs::metatest::to_stream_integral_constant<
          typename T::value_type,
          T::value
        >
      {};
    };

    struct to_stream_nothing
    {
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
    
    MPLLIBS_TO_STREAM_SEQUENCE(boost::mpl::aux::vector_tag, vector)
    MPLLIBS_TO_STREAM_SEQUENCE(boost::mpl::aux::list_tag, list)
    MPLLIBS_TO_STREAM_SEQUENCE(boost::mpl::aux::half_open_range_tag, range)
    
    #undef MPLLIBS_TO_STREAM_SEQUENCE

    template <>
    struct to_stream_impl<boost::mpl::string_tag>
    {
      template <class S>
      struct apply
      {
        static std::ostream& run(std::ostream& o_)
        {
          o_ << "string<\"";
          boost::mpl::for_each<S>(character_printer(o_));
          return o_ << "\">";
        }
      };
    };

    template <>
    struct to_stream<boost::mpl::void_>
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << "void_";
      }
    };

    template <>
    struct to_stream<boost::mpl::string<> >
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << "void_";
      }
    };

    template <int N>
    struct to_stream<boost::mpl::arg<N> >
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << "_" << N;
      }
    };
  }
}    

#ifdef MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE
  #error MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE already defined
#endif
#define MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(t, name) \
  namespace mpllibs \
  { \
    namespace metatest \
    { \
      template <> \
      struct to_stream<t> \
      { \
        typedef to_stream type; \
        \
        static std::ostream& run(std::ostream& o_) \
        { \
          return o_ << name; \
        } \
      }; \
    } \
  }

#ifdef MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE
  #error MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE already defined
#endif
#define MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(t) \
  MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(t, #t)

#ifdef MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_N
  #error MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_N already defined
#endif
#define MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_N(z, n, unused) \
  mpllibs::metatest::to_stream<A##n>::run(o_ << ", ");

#ifdef MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE
  #error MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE already defined
#endif
#define MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(n, t, name) \
  namespace mpllibs \
  { \
    namespace metatest \
    { \
      template <BOOST_PP_ENUM_PARAMS(n, class A)> \
      struct to_stream<t<BOOST_PP_ENUM_PARAMS(n, A)> > \
      { \
        typedef to_stream type; \
        \
        static std::ostream& run(std::ostream& o_) \
        { \
          mpllibs::metatest::to_stream<A0>::run(o_ << name << "<"); \
          BOOST_PP_REPEAT_FROM_TO( \
            1, \
            n, \
            MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_N, \
            ~ \
          ) \
          return o_ << ">"; \
        } \
      }; \
    } \
  }

#ifdef MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION
  #error MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION already defined
#endif
#define MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(n, t, name) \
  namespace mpllibs \
  { \
    namespace metatest \
    { \
      template <BOOST_PP_ENUM_PARAMS(n, class A)> \
      struct to_stream<t<BOOST_PP_ENUM_PARAMS(n, A)> > \
      { \
        typedef to_stream type; \
        \
        static std::ostream& run(std::ostream& o_) \
        { \
          o_ << name << "<???"; \
          for (int i = 1; i < n; ++i) \
          { \
            o_ << ", ???"; \
          } \
          return o_ << ">"; \
        } \
      }; \
    } \
  }

MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(char)
MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(signed char)
MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(unsigned char)

MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(short)
MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(unsigned short)

MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(int)
MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(unsigned int)

MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(long)
MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(unsigned long)

MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(float)
MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(double)

MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(bool)

MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(void)

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(boost::mpl::empty_sequence, "empty_sequence")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::filter_view, "filter_view")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  boost::mpl::iterator_range,
  "iterator_range"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::joint_view, "joint_view")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::single_view, "single_view")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  boost::mpl::transform_view,
  "transform_view"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::zip_view, "zip_view")

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::at, "at")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::back, "back")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  1,
  boost::mpl::begin,
  "begin"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  1,
  boost::mpl::clear,
  "clear"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  1,
  boost::mpl::empty,
  "empty"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::end, "end")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::erase,
  "erase"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  2,
  boost::mpl::erase_key,
  "erase_key"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  1,
  boost::mpl::front,
  "front"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  2,
  boost::mpl::has_key,
  "has_key"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::insert,
  "insert"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::insert_range,
  "insert_range"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  1,
  boost::mpl::is_sequence,
  "is_sequence"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  2,
  boost::mpl::key_type,
  "key_type"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  2,
  boost::mpl::order,
  "order"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  1,
  boost::mpl::pop_back,
  "pop_back"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  1,
  boost::mpl::pop_front,
  "pop_front"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  2,
  boost::mpl::push_back,
  "push_back"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  2,
  boost::mpl::push_front,
  "push_front"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  1,
  boost::mpl::sequence_tag,
  "sequence_tag"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::size, "size")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  1,
  boost::mpl::value_type,
  "value_type"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  2,
  boost::mpl::advance,
  "advance"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  2,
  boost::mpl::distance,
  "distance"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::next, "next")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  1,
  boost::mpl::prior,
  "prior"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  1,
  boost::mpl::deref,
  "deref"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  1,
  boost::mpl::iterator_category,
  "iterator_category"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  boost::mpl::back_inserter,
  "back_inserter"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  boost::mpl::front_inserter,
  "front_inserter"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::inserter, "inserter")

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::fold, "fold")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::iter_fold,
  "iter_fold"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::reverse_fold,
  "reverse_fold"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::reverse_iter_fold,
  "reverse_iter_fold"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::accumulate,
  "accumulate"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::find, "find")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  2,
  boost::mpl::find_if,
  "find_if"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  2,
  boost::mpl::contains,
  "contains"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  2,
  boost::mpl::count,
  "count"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  2,
  boost::mpl::count_if,
  "count_if"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::lower_bound, "lower_bound")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::upper_bound, "upper_bound")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::min_element, "min_element")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::max_element, "max_element")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::equal, "equal")

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::copy, "copy")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::copy_if,
  "copy_if"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::transform,
  "transform"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  4,
  boost::mpl::replace,
  "replace"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  4,
  boost::mpl::replace_if,
  "replace_if"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::remove,
  "remove"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::remove_if,
  "remove_if"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::unique,
  "unique"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  4,
  boost::mpl::partition,
  "partition"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  4,
  boost::mpl::stable_partition,
  "stable_partition"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::sort, "sort")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  2,
  boost::mpl::reverse,
  "reverse"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  2,
  boost::mpl::reverse_copy,
  "reverse_copy"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::reverse_copy_if,
  "reverse_copy_if"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::reverse_transform,
  "reverse_transform"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  4,
  boost::mpl::reverse_replace,
  "reverse_replace"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::reverse_replace_if,
  "reverse_replace_if"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::reverse_remove,
  "reverse_remove"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::reverse_remove_if,
  "reverse_remove_if"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::reverse_unique,
  "reverse_unique"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  4,
  boost::mpl::reverse_partition,
  "reverse_partition"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  4,
  boost::mpl::reverse_stable_partition,
  "reverse_stable_partition"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::if_, "if_")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  3,
  boost::mpl::eval_if,
  "eval_if"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  1,
  boost::mpl::unpack_args,
  "unpack_args"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  2,
  boost::mpl::lambda,
  "lambda"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  1,
  boost::mpl::protect,
  "protect"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::modulus, "modulus")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::negate, "negate")

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::less, "less")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::less_equal, "less_equal")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::greater, "greater")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  boost::mpl::greater_equal,
  "greater_equal"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::equal_to, "equal_to")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  boost::mpl::not_equal_to,
  "not_equal_to"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::not_, "not_")

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::shift_left, "shift_left")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::shift_right, "shift_right")

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::first, "first")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::second, "second")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::base, "base")

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::c_str, "c_str")

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(
  1,
  boost::mpl::identity,
  "identity"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::always, "always")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::inherit, "inherit")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  3,
  boost::mpl::inherit_linearly,
  "inherit_linearly"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  boost::mpl::numeric_cast,
  "numeric_cast"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::min, "min")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::max, "max")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::sizeof_, "sizeof_")

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::pair, "pair")

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(boost::mpl::empty_base, "empty_base")

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::is_same, "is_same")

#ifdef MPLLIBS_MULTI_ARG_METAFUNCTION
  #error MPLLIBS_MULTI_ARG_METAFUNCTION already defined
#endif
#define MPLLIBS_MULTI_ARG_METAFUNCTION(z, n, name) \
  MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(n, boost::mpl::name, #name)

#ifdef MPLLIBS_DEF_MULTI_ARG
  #error MPLLIBS_DEF_MULTI_ARG already defined
#endif
#define MPLLIBS_DEF_MULTI_ARG(name) \
  BOOST_PP_REPEAT_FROM_TO( \
    1, \
    BOOST_MPL_LIMIT_METAFUNCTION_ARITY, \
    MPLLIBS_MULTI_ARG_METAFUNCTION, \
    name \
  )
  
MPLLIBS_DEF_MULTI_ARG(apply)
MPLLIBS_DEF_MULTI_ARG(bind)
MPLLIBS_DEF_MULTI_ARG(plus)
MPLLIBS_DEF_MULTI_ARG(minus)
MPLLIBS_DEF_MULTI_ARG(times)
MPLLIBS_DEF_MULTI_ARG(divides)
MPLLIBS_DEF_MULTI_ARG(and_)
MPLLIBS_DEF_MULTI_ARG(or_)
MPLLIBS_DEF_MULTI_ARG(bitand_)
MPLLIBS_DEF_MULTI_ARG(bitor_)
MPLLIBS_DEF_MULTI_ARG(bitxor_)

#undef MPLLIBS_DEF_MULTI_ARG
#undef MPLLIBS_MULTI_ARG_METAFUNCTION


#endif

