#ifndef MPLLIBS_UTIL_LAZY_EQUAL_TO_H
#define MPLLIBS_UTIL_LAZY_EQUAL_TO_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/equal_to.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      // Accepts nullary metafunctions
      template <class a, class b>
      struct lazy_equal_to :
        boost::mpl::equal_to<typename a::type, typename b::type>
      {};
    }
  }
}

#endif

