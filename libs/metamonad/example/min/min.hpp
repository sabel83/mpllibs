#ifndef MPLLIBS_METAMONAD_EXAMPLE_MIN_HPP
#define MPLLIBS_METAMONAD_EXAMPLE_MIN_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "less.hpp"

#include <mpllibs/metamonad/try_c.hpp>
#include <mpllibs/metamonad/apply.hpp>
#include <mpllibs/metamonad/if.hpp>

template <class TagA, class TagB>
struct min_impl
{
  typedef min_impl type;

  template <class A, class B>
  struct apply :
    mpllibs::metamonad::try_c<mpllibs::metamonad::if_<less<A, B>, A, B> >
  {};
};

template <class A, class B>
struct min :
  mpllibs::metamonad::apply<
    min_impl<
      typename boost::mpl::tag<typename A::type>::type,
      typename boost::mpl::tag<typename B::type>::type
    >,
    A,
    B
  >
{};

#endif

