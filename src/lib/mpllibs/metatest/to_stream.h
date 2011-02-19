#ifndef MPLLIBS_TEST_TO_STREAM_H
#define MPLLIBS_TEST_TO_STREAM_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/integral_c.hpp>

#include <boost/mpl/void.hpp>
#include <boost/mpl/string.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/aux_/range_c/tag.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/empty.hpp>

#include <boost/mpl/fold.hpp>

#include <boost/mpl/for_each.hpp>

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
    
    template <class seq>
    struct to_stream_sequence_begin<seq, boost::mpl::integral_c_tag>
    {
      typedef to_stream_sequence_begin type;
      
      static std::ostream& run(std::ostream& o_)
      {
        using boost::mpl::begin;
        using boost::mpl::end;
        
        o_ << "_c<";
        mpllibs::metatest::to_stream<typename seq::value_type>::run(o_);
        o_ << ", ";
        
        if (boost::is_same<char, typename seq::value_type>::type::value)
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

#endif

