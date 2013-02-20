#ifndef MPLLIBS_METAMONAD_PAIR_HPP
#define MPLLIBS_METAMONAD_PAIR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

#include <boost/mpl/pair.hpp>
#include <boost/mpl/vector.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct pair_tag : tmp_tag<pair_tag> {};

    template <class A = boost::mpl::na, class B = boost::mpl::na>
    struct pair
    {
      typedef pair<typename A::type, typename B::type> type;
      typedef pair_tag tag;

      // Compatibility with Boost.MPL's pair
      typedef A first;
      typedef B second;
    };

    template <class A>
    struct pair<A, boost::mpl::na> :
      tmp_value<pair<A, boost::mpl::na>, pair_tag>
    {
      template <class B = boost::mpl::na>
      struct apply : pair<A, B> {};
    };

    template <>
    struct pair<boost::mpl::na, boost::mpl::na> :
      tmp_value<pair<boost::mpl::na, boost::mpl::na>, pair_tag>
    {
      template <class A = boost::mpl::na, class B = boost::mpl::na>
      struct apply : pair<A, B> {};
    };
  }
}

#endif

