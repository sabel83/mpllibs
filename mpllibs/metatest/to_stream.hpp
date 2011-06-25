#ifndef MPLLIBS_METATEST_TO_STREAM_HPP
#define MPLLIBS_METATEST_TO_STREAM_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/tag.hpp>

#include <iostream>

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
      boost::mpl::apply_wrap1<
        to_stream_impl<typename boost::mpl::tag<T>::type>,
        T
      >
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

#ifndef MPLLIBS_NO_TO_STREAM_MPL
#include <mpllibs/metatest/to_stream_mpl.hpp>
#endif

#endif

