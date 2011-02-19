#ifndef MPLLIBS_TEST_TO_STREAM_H
#define MPLLIBS_TEST_TO_STREAM_H

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
    template <class t>
    struct to_stream_impl
    {
      template <class T>
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
        return mpllibs::metatest::to_stream<T>::run(o_) << "*";
      }
    };

    template <class T>
    struct to_stream<T[]>
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return mpllibs::metatest::to_stream<T>::run(o_) << "[]";
      }
    };

    template <class T>
    struct to_stream<T&>
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return mpllibs::metatest::to_stream<T>::run(o_) << "&";
      }
    };

    template <class T>
    struct to_stream<const T>
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return mpllibs::metatest::to_stream<T>::run(o_ << "const ");
      }
    };

    template <class T>
    struct to_stream<T* const>
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return mpllibs::metatest::to_stream<T>::run(o_) << "* const";
      }
    };



    template <class ValueType, ValueType value>
    struct to_stream_integral_constant
    {
      typedef to_stream_integral_constant type;
        
      static std::ostream& run(std::ostream& o_)
      {
        return
          mpllibs::metatest::to_stream<ValueType>::run(o_ << "integral_c<")
          << ", " << value << ">";
      }
    };

    template <bool value>
    struct to_stream_integral_constant<bool, value>
    {
      typedef to_stream_integral_constant type;
        
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << (value ? "true_" : "false_");
      }
    };

    template <int value>
    struct to_stream_integral_constant<int, value>
    {
      typedef to_stream_integral_constant type;
        
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << "int_<" << value << ">";
      }
    };

    template <long value>
    struct to_stream_integral_constant<long, value>
    {
      typedef to_stream_integral_constant type;
        
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << "long_<" << value << ">";
      }
    };
    
    class CharacterPrinter
    {
    public:
      CharacterPrinter(std::ostream& o_) : _o(o_) {}
    
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
            _o << "\\x";
            
            const std::ios_base::fmtflags f = _o.flags();
            _o.flags(std::ios::hex);
            _o << (c_ & 0xf0) << (c_ & 0x0f);
            _o.flags(f);
          }
        }
      }
    private:
      std::ostream& _o;
    };

    template <char value>
    struct to_stream_integral_constant<char, value>
    {
      typedef to_stream_integral_constant type;
        
      static std::ostream& run(std::ostream& o_)
      {
        assert(sizeof(char) == 1);

        o_ << "char_<\'";
        mpllibs::metatest::CharacterPrinter(o_).operator()(value);
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

    template <class i, class end>
    struct to_stream_sequence_impl;

    template <class i, class end>
    struct to_stream_sequence :
      boost::mpl::if_<
        boost::is_same<i, end>,
        mpllibs::metatest::to_stream_nothing,
        mpllibs::metatest::to_stream_sequence_impl<i, end>
      >::type
    {};
    
    template <class i, class end>
    struct to_stream_sequence_impl
    {
      static std::ostream& run(std::ostream& o_)
      {
        using boost::mpl::next;
        using boost::mpl::deref;
        using boost::is_same;
        
        typedef typename next<i>::type i_next;
        
        return
          mpllibs::metatest::to_stream_sequence<i_next, end>::run(
            mpllibs::metatest::to_stream<typename deref<i>::type>::run(o_)
              << (is_same<i_next, end>::type::value ? "" : ", ")
          );
      }
    };
    

    template <class i, class end>
    struct to_stream_sequence_values_impl;

    template <class i, class end>
    struct to_stream_sequence_values :
      boost::mpl::if_<
        boost::is_same<i, end>,
        mpllibs::metatest::to_stream_nothing,
        mpllibs::metatest::to_stream_sequence_values_impl<i, end>
      >::type
    {};
    
    template <class i, class end>
    struct to_stream_sequence_values_impl
    {
      static std::ostream& run(std::ostream& o_)
      {
        using boost::mpl::next;
        using boost::mpl::deref;
        using boost::is_same;
        
        typedef typename next<i>::type i_next;
        
        return
          mpllibs::metatest::to_stream_sequence_values<i_next, end>::run(
            o_
              << deref<i>::type::value
              << (is_same<i_next, end>::type::value ? "" : ", ")
          );
      }
    };

    struct no_common_tag
    {
      typedef no_common_tag type;
    };
    
    // I can't use a lambda expression, because is_same is not lazy
    struct common_tag_compare
    {
      template <class a, class b>
      struct apply :
        boost::mpl::if_<
          boost::is_same<a, typename boost::mpl::tag<b>::type>,
          a,
          mpllibs::metatest::no_common_tag
        >
      {};
    };
    
    template <class seq>
    struct common_tag :
      boost::mpl::fold<
        seq,
        typename boost::mpl::tag<typename boost::mpl::front<seq>::type>::type,
        mpllibs::metatest::common_tag_compare
      >
    {};
    
    template <class seq, class common_tag>
    struct to_stream_sequence_begin
    {
      typedef to_stream_sequence_begin type;
      
      static std::ostream& run(std::ostream& o_)
      {
        using boost::mpl::begin;
        using boost::mpl::end;
        
        return
          mpllibs::metatest::to_stream_sequence<
            typename begin<seq>::type,
            typename end<seq>::type
          >::run(o_ << "<") << ">";
      }
    };
    
    // pre-condition: !empty<seq>
    template <class seq>
    struct to_stream_sequence_begin<seq, boost::mpl::integral_c_tag>
    {
      typedef to_stream_sequence_begin type;
      
      static std::ostream& run(std::ostream& o_)
      {
        using boost::mpl::begin;
        using boost::mpl::end;
        using boost::mpl::front;
        
        typedef typename front<seq>::type::value_type v_type;
        
        o_ << "_c<";
        mpllibs::metatest::to_stream<v_type>::run(o_);
        o_ << ", ";
        
        if (boost::is_same<char, v_type>::type::value)
        {
          o_ << '\"';
          boost::mpl::for_each<seq>(mpllibs::metatest::CharacterPrinter(o_));
          o_ << '\"';
        }
        else
        {
          mpllibs::metatest::to_stream_sequence_values<
            typename begin<seq>::type,
            typename end<seq>::type
          >::run(o_);
        }
          
        return o_ << ">";
      }
    };

    #ifdef TO_STREAM_SEQUENCE
      #error TO_STREAM_SEQUENCE already defined
    #endif
    #define TO_STREAM_SEQUENCE(tag, name) \
      template <> \
      struct to_stream_impl<tag> \
      { \
        template <class seq> \
        struct apply \
        { \
          typedef apply type; \
          \
          static std::ostream& run(std::ostream& o_) \
          { \
            return \
              mpllibs::metatest::to_stream_sequence_begin< \
                seq, \
                typename boost::mpl::eval_if< \
                  typename boost::mpl::empty<seq>::type, \
                  mpllibs::metatest::no_common_tag, \
                  mpllibs::metatest::common_tag<seq> \
                >::type \
              >::run(o_ << "mpl::" #name); \
          } \
        }; \
      };
    
    TO_STREAM_SEQUENCE(boost::mpl::aux::vector_tag, vector)
    TO_STREAM_SEQUENCE(boost::mpl::aux::list_tag, list)
    TO_STREAM_SEQUENCE(boost::mpl::aux::half_open_range_tag, range)
    
    #undef TO_STREAM_SEQUENCE

    template <>
    struct to_stream_impl<boost::mpl::string_tag>
    {
      template <class s>
      struct apply
      {
        static std::ostream& run(std::ostream& o_)
        {
          o_ << "string<\"";
          boost::mpl::for_each<s>(mpllibs::metatest::CharacterPrinter(o_));
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

    template <int n>
    struct to_stream<boost::mpl::arg<n> >
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << "_" << n;
      }
    };
  }
}    

#ifdef DEFINE_TO_STREAM_FOR_TYPE
  #error DEFINE_TO_STREAM_FOR_TYPE already defined
#endif
#define DEFINE_TO_STREAM_FOR_TYPE(t, name) \
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

#ifdef DEFINE_TO_STREAM_FOR_SIMPLE_TYPE
  #error DEFINE_TO_STREAM_FOR_SIMPLE_TYPE already defined
#endif
#define DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(t) DEFINE_TO_STREAM_FOR_TYPE(t, #t)

#ifdef DEFINE_TO_STREAM_FOR_TEMPLATE_N
  #error DEFINE_TO_STREAM_FOR_TEMPLATE_N already defined
#endif
#define DEFINE_TO_STREAM_FOR_TEMPLATE_N(z, n, unused) \
  mpllibs::metatest::to_stream<a##n>::run(o_ << ", ");

#ifdef DEFINE_TO_STREAM_FOR_TEMPLATE
  #error DEFINE_TO_STREAM_FOR_TEMPLATE already defined
#endif
#define DEFINE_TO_STREAM_FOR_TEMPLATE(n, t, name) \
  namespace mpllibs \
  { \
    namespace metatest \
    { \
      template <BOOST_PP_ENUM_PARAMS(n, class a)> \
      struct to_stream<t<BOOST_PP_ENUM_PARAMS(n, a)> > \
      { \
        typedef to_stream type; \
        \
        static std::ostream& run(std::ostream& o_) \
        { \
          mpllibs::metatest::to_stream<a0>::run(o_ << name << "<"); \
          BOOST_PP_REPEAT_FROM_TO(1, n, DEFINE_TO_STREAM_FOR_TEMPLATE_N, ~) \
          return o_ << ">"; \
        } \
      }; \
    } \
  }

#ifdef DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION
  #error DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION already defined
#endif
#define DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(n, t, name) \
  namespace mpllibs \
  { \
    namespace metatest \
    { \
      template <BOOST_PP_ENUM_PARAMS(n, class a)> \
      struct to_stream<t<BOOST_PP_ENUM_PARAMS(n, a)> > \
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

DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(char)
DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(signed char)
DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(unsigned char)

DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(short)
DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(unsigned short)

DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(int)
DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(unsigned int)

DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(long)
DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(unsigned long)

DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(float)
DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(double)

DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(bool)

DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(void)

DEFINE_TO_STREAM_FOR_TYPE(boost::mpl::empty_sequence, "empty_sequence")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::filter_view, "filter_view")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::iterator_range, "iterator_range")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::joint_view, "joint_view")
DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::single_view, "single_view")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::transform_view, "transform_view")
DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::zip_view, "zip_view")

DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::at, "at")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::back, "back")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::begin, "begin")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::clear, "clear")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::empty, "empty")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::end, "end")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::erase, "erase")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::erase_key, "erase_key")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::front, "front")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::has_key, "has_key")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::insert, "insert")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::insert_range, "insert_range")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::is_sequence, "is_sequence")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::key_type, "key_type")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::order, "order")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::pop_back, "pop_back")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::pop_front, "pop_front")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::push_back, "push_back")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::push_front, "push_front")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::sequence_tag, "sequence_tag")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::size, "size")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::value_type, "value_type")

DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::advance, "advance")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::distance, "distance")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::next, "next")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::prior, "prior")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::deref, "deref")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::iterator_category, "iterator_category")

DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::back_inserter, "back_inserter")
DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::front_inserter, "front_inserter")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::inserter, "inserter")

DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::fold, "fold")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::iter_fold, "iter_fold")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::reverse_fold, "reverse_fold")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::reverse_iter_fold, "reverse_iter_fold")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::accumulate, "accumulate")

DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::find, "find")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::find_if, "find_if")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::contains, "contains")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::count, "count")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::count_if, "count_if")
DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::lower_bound, "lower_bound")
DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::upper_bound, "upper_bound")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::min_element, "min_element")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::max_element, "max_element")
DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::equal, "equal")

DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::copy, "copy")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::copy_if, "copy_if")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::transform, "transform")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(4, boost::mpl::replace, "replace")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(4, boost::mpl::replace_if, "replace_if")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::remove, "remove")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::remove_if, "remove_if")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::unique, "unique")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(4, boost::mpl::partition, "partition")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(4, boost::mpl::stable_partition, "stable_partition")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::sort, "sort")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::reverse, "reverse")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::reverse_copy, "reverse_copy")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::reverse_copy_if, "reverse_copy_if")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::reverse_transform, "reverse_transform")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(4, boost::mpl::reverse_replace, "reverse_replace")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::reverse_replace_if, "reverse_replace_if")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::reverse_remove, "reverse_remove")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::reverse_remove_if, "reverse_remove_if")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::reverse_unique, "reverse_unique")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(4, boost::mpl::reverse_partition, "reverse_partition")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(4, boost::mpl::reverse_stable_partition, "reverse_stable_partition")

DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::if_, "if_")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(3, boost::mpl::eval_if, "eval_if")

DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::unpack_args, "unpack_args")

DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(2, boost::mpl::lambda, "lambda")
DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::protect, "protect")

DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::modulus, "modulus")
DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::negate, "negate")

DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::less, "less")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::less_equal, "less_equal")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::greater, "greater")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::greater_equal, "greater_equal")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::equal_to, "equal_to")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::not_equal_to, "not_equal_to")

DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::not_, "not_")

DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::shift_left, "shift_left")
DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::shift_right, "shift_right")

DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::first, "first")
DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::second, "second")
DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::base, "base")

DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::c_str, "c_str")

DEFINE_TO_STREAM_FOR_TEMPLATE_NO_RECURSION(1, boost::mpl::identity, "identity")
DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::always, "always")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::inherit, "inherit")
DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::inherit_linearly, "inherit_linearly")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::numeric_cast, "numeric_cast")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::min, "min")
DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::max, "max")
DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::sizeof_, "sizeof_")

DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::pair, "pair")

DEFINE_TO_STREAM_FOR_TYPE(boost::mpl::empty_base, "empty_base")

DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::is_same, "is_same")

#ifdef MULTI_ARG_METAFUNCTION
  #error MULTI_ARG_METAFUNCTION already defined
#endif
#define MULTI_ARG_METAFUNCTION(z, n, name) \
  DEFINE_TO_STREAM_FOR_TEMPLATE(n, boost::mpl::name, #name)

#ifdef DEF_MULTI_ARG
  #error DEF_MULTI_ARG already defined
#endif
#define DEF_MULTI_ARG(name) \
  BOOST_PP_REPEAT_FROM_TO( \
    1, \
    BOOST_MPL_LIMIT_METAFUNCTION_ARITY, \
    MULTI_ARG_METAFUNCTION, \
    name \
  )
  
DEF_MULTI_ARG(apply)
DEF_MULTI_ARG(bind)
DEF_MULTI_ARG(plus)
DEF_MULTI_ARG(minus)
DEF_MULTI_ARG(times)
DEF_MULTI_ARG(divides)
DEF_MULTI_ARG(and_)
DEF_MULTI_ARG(or_)
DEF_MULTI_ARG(bitand_)
DEF_MULTI_ARG(bitor_)
DEF_MULTI_ARG(bitxor_)

#undef DEF_MULTI_ARG
#undef MULTI_ARG_METAFUNCTION


#endif

