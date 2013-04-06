#ifndef MPLLIBS_METAMONAD_EXAMPLE_LESS_HPP
#define MPLLIBS_METAMONAD_EXAMPLE_LESS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/apply.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>

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
    struct equal_to_impl<non_comparable_tag, non_comparable_tag> :
      mpllibs::metamonad::lambda_c<
        mpllibs::metamonad::_,
        mpllibs::metamonad::_,
        true_
      >
    {};
    
    template <class T>
    struct equal_to_impl<non_comparable_tag, T> : always<false_> {};

    template <class T>
    struct equal_to_impl<T, non_comparable_tag> :
      equal_to_impl<non_comparable_tag, T>
    {};
  }
}

template <class TagA, class TagB>
struct less_impl :
  mpllibs::metamonad::lambda_c<
    mpllibs::metamonad::_,
    mpllibs::metamonad::_,
    mpllibs::metamonad::exception<non_comparable>
  >
{};

template <class A, class B>
struct less :
  mpllibs::metamonad::apply<
    less_impl<
      typename boost::mpl::tag<typename A::type>::type,
      typename boost::mpl::tag<typename B::type>::type
    >,
    A,
    B
  >
{};

typedef boost::mpl::tag<boost::mpl::int_<0> >::type int_tag;

template <>
struct less_impl<int_tag, int_tag>
{
  typedef less_impl type;

  // Visual C++ 2010 fails to compile it when operator< is used instead of
  // operator >
  template <class A, class B>
  struct apply : boost::mpl::bool_< !(A::value > B::value)> {};
};

#endif

