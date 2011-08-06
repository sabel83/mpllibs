#ifndef MPLLIBS_METATEST_MIN_HPP
#define MPLLIBS_METATEST_MIN_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "less.hpp"

#include <mpllibs/metamonad/throw.hpp>
#include <mpllibs/metamonad/do_try.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/if.hpp>

struct c;

template <class TagA, class TagB>
struct min_impl
{
  template <class A, class B>
  struct apply :
    do_try<
      mpllibs::metamonad::set<c, less<A, B> >,
      boost::mpl::if_<c, A, B>
    >
  {};
};

template <class A, class B>
struct min :
  boost::mpl::apply_wrap2<
    min_impl<
      typename boost::mpl::tag<typename A::type>::type,
      typename boost::mpl::tag<typename B::type>::type
    >,
    typename A::type,
    typename B::type
  >
{
  struct to_stream
  {
    static std::ostream& run(std::ostream& o)
    {
      o << "min<";
      mpllibs::metatest::to_stream_argument_list<A, B>::run(o);
      return o << ">";
    }
  };
};

#endif

