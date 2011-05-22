#ifndef LESS_H
#define LESS_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/throw.hpp>

#include <boost/mpl/apply.hpp>

struct non_comparable_tag
{
  typedef non_comparable_tag type;
};

struct non_comparable
{
  typedef non_comparable_tag tag;
  typedef non_comparable type;
};

namespace boost
{
  namespace mpl
  {
    template <>
    struct equal_to_impl<non_comparable_tag, non_comparable_tag>
    {
      template <class A, class B>
      struct apply :  boost::mpl::true_ {};
    };
    
    template <class T>
    struct equal_to_impl<non_comparable_tag, T>
    {
      template <class A, class B>
      struct apply :  boost::mpl::false_ {};
    };

    template <class T>
    struct equal_to_impl<T, non_comparable_tag> :
      equal_to_impl<non_comparable_tag, T>
    {};
  }
}

template <class TagA, class TagB>
struct less_impl
{
  template <class A, class B>
  struct apply : THROW<non_comparable> {};
};

template <class A, class B>
struct less :
  boost::mpl::apply<
    less_impl<
      typename boost::mpl::tag<typename A::type>::type,
      typename boost::mpl::tag<typename B::type>::type
    >,
    typename A::type,
    typename B::type
  >
{};

typedef boost::mpl::tag<boost::mpl::int_<0> >::type int_tag;

template <>
struct less_impl<int_tag, int_tag>
{
  template <class A, class B>
  struct apply : boost::mpl::bool_<(A::value < B::value)> {};
};

#endif

