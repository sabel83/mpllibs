#ifndef MPLLIBS_METATEST_LESS_HPP
#define MPLLIBS_METATEST_LESS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/throw.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/equal_to.hpp>

struct non_comparable_tag : mpllibs::metamonad::tmp_tag<non_comparable_tag> {};
struct non_comparable :
  mpllibs::metamonad::tmp_value<non_comparable, non_comparable_tag>
{};

namespace boost
{
  namespace mpl
  {
    template <>
    struct equal_to_impl<non_comparable_tag, non_comparable_tag>
    {
      template <class A, class B>
      struct apply : boost::mpl::true_ {};
    };
    
    template <class T>
    struct equal_to_impl<non_comparable_tag, T>
    {
      template <class A, class B>
      struct apply : boost::mpl::false_ {};
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
  struct apply : mpllibs::metamonad::throw_<non_comparable> {};
};

template <class A, class B>
struct less :
  boost::mpl::apply_wrap2<
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
  struct apply
  {
    static const int value = A::value < B::value;

    typedef boost::mpl::bool_<value> type;
  };
};

#endif

