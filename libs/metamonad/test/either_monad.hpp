#ifndef MPLLIBS_METAMONAD_TEST_EITHER_MONAD_HPP
#define MPLLIBS_METAMONAD_TEST_EITHER_MONAD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/tag.hpp>

#include <boost/type_traits/is_same.hpp>

namespace
{
  /*
   * Either monad for testing
   */
  MPLLIBS_DEFINE_TAG(either_tag)
  MPLLIBS_DEFINE_TAG(left_tag)
  MPLLIBS_DEFINE_TAG(right_tag)

  typedef either_tag either;
  
  template <class T>
  struct left
  {
    typedef left_tag tag;
    typedef T value;
    typedef left type;
    
    struct to_stream
    {
      static std::ostream& run(std::ostream& o)
      {
        o << "left<";
        mpllibs::metatest::to_stream_argument_list<T>::run(o);
        return o << ">";
      }
    };
  };
  
  template <class T>
  struct right
  {
    typedef right_tag tag;
    typedef T value;
    typedef right type;
    
    struct to_stream
    {
      static std::ostream& run(std::ostream& o)
      {
        o << "right<";
        mpllibs::metatest::to_stream_argument_list<T>::run(o);
        return o << ">";
      }
    };
  };
}

namespace mpllibs
{
  namespace metamonad
  {
    template <>
    struct return__impl<either_tag>
    {
      template <class T>
      struct apply : right<T> {};
    };
  }
}

namespace boost
{
  namespace mpl
  {
    template <>
    struct equal_to_impl<left_tag, left_tag>
    {
      template <class A, class B>
      struct apply :
        boost::mpl::equal_to<typename A::value, typename B::value>
      {};
    };

    template <>
    struct equal_to_impl<right_tag, right_tag> :
      equal_to_impl<left_tag, left_tag>
    {};

    template <>
    struct equal_to_impl<right_tag, left_tag>
    {
      template <class A, class B>
      struct apply : boost::mpl::identity<boost::mpl::false_>
      {};
    };
    
    template <>
    struct equal_to_impl<left_tag, right_tag> :
      equal_to_impl<right_tag, left_tag>
    {};
  }
}

namespace mpllibs
{
  namespace metamonad
  {
    template <>
    struct bind_impl<either_tag>
    {
      template <class A, class F>
      struct apply :
        boost::mpl::if_<
          typename boost::is_same<
            right_tag,
            typename boost::mpl::tag<A>::type
          >::type,
          boost::mpl::apply<F, A>,
          A
        >::type
      {};
    };
    
    template <>
    struct bind_impl<right_tag> : bind_impl<either_tag> {};
  
    template <>
    struct bind_impl<left_tag> : bind_impl<either_tag> {};
  }
}

#endif


