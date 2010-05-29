#ifndef MPLLIBS_UTIL_LAZY_IF_H
#define MPLLIBS_UTIL_LAZY_IF_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/if.hpp>

namespace mpllibs
{
  namespace util
  {
    // Accepts nullary metafunction as condition
    template <class c, class t, class f>
    struct lazy_if : boost::mpl::if_<typename c::type, t, f> {};
  }
}

#endif

