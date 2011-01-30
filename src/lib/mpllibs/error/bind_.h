#ifndef MPLLIBS_ERROR_BIND__H
#define MPLLIBS_ERROR_BIND__H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/bind.h>
#include <mpllibs/error/util/id.h>

#include <boost/mpl/always.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/tag.hpp>

namespace mpllibs
{
  namespace error
  {
    template <class, class>
    struct bind__impl
    {
      template <class a, class b>
      struct apply :
        mpllibs::error::bind<
          mpllibs::error::util::id<a>,
          mpllibs::error::util::id<boost::mpl::always<b> >
        >
      {};
    };

    // bind_ evaluates its arguments lazily
    template <class a, class b>
    struct bind_ :
      boost::mpl::apply<
        mpllibs::error::bind__impl<
          typename boost::mpl::tag<typename a::type>::type,
          typename boost::mpl::tag<typename a::type>::type
        >,
        typename a::type,
        typename b::type
      >
    {};
  }
}

#endif

