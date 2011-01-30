#ifndef MPLLIBS_ERROR_BIND_H
#define MPLLIBS_ERROR_BIND_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/apply.hpp>
#include <boost/mpl/tag.hpp>

namespace mpllibs
{
  namespace error
  {
    template <class, class>
    struct bind_impl;
    // No default implementation
    
    // bind evaluates arguments lazily
    template <class a, class f>
    struct bind :
      boost::mpl::apply<
        mpllibs::error::bind_impl<
          typename boost::mpl::tag<typename a::type>::type,
          typename boost::mpl::tag<typename f::type>::type
        >,
        typename a::type,
        typename f::type
      >
    {};
  }
}

#endif

