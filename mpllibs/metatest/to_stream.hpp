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

