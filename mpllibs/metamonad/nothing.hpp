#ifndef MPLLIBS_METAMONAD_NOTHING_HPP
#define MPLLIBS_METAMONAD_NOTHING_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tag_tag.hpp>
#include <mpllibs/metamonad/meta_atom.hpp>

#include <boost/mpl/bool.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_DEFINE_TAG(nothing_tag)
    
    MPLLIBS_DEFINE_META_ATOM(nothing_tag, nothing)
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
      template <class A, class B>
      struct apply : boost::mpl::true_ {};
    };
  }
}

#endif

