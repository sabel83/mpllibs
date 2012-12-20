#ifndef MPLLIBS_METAMONAD_NOTHING_HPP
#define MPLLIBS_METAMONAD_NOTHING_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

#include <boost/mpl/bool.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct nothing_tag : tmp_tag<nothing_tag> {};
    struct nothing : tmp_value<nothing, nothing_tag> {};
  }
}

namespace boost
{
  namespace mpl
  {
    template <class A, class B>
    struct equal_to_impl;

    template <>
    struct
      equal_to_impl<
        mpllibs::metamonad::nothing_tag,
        mpllibs::metamonad::nothing_tag
      >
    {
      MPLLIBS_METAFUNCTION(apply, (A)(B)) ((boost::mpl::true_));
    };
  }
}

#endif

