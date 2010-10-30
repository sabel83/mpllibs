#ifndef MPLLIBS_PARSER_NOTHING_H
#define MPLLIBS_PARSER_NOTHING_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/bool.hpp>
#include <boost/mpl/identity.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    struct nothing_tag {};

    struct nothing
    {
      typedef nothing_tag tag;
      
      typedef nothing type;
    };
  }
}

namespace boost
{
  namespace mpl
  {
    template <class a, class b>
    struct equal_to_impl;

    template <>
    struct
      equal_to_impl<
        mpllibs::metaparse::nothing_tag,
        mpllibs::metaparse::nothing_tag
      >
    {
      template <class a, class b>
      struct apply : boost::mpl::identity<boost::mpl::true_> {};
    };

    template <class c>
    struct equal_to_impl<c, mpllibs::metaparse::nothing_tag>
    {
      template <class a, class b>
      struct apply : boost::mpl::identity<boost::mpl::false_> {};
    };

    template <class c>
    struct equal_to_impl<mpllibs::metaparse::nothing_tag, c>
    {
      template <class a, class b>
      struct apply : boost::mpl::identity<boost::mpl::false_> {};
    };
  }
}

#endif

