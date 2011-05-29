#ifndef MPLLIBS_UTIL_CONS_H
#define MPLLIBS_UTIL_CONS_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/push_front.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      struct cons
      {
        template <class P>
        struct apply :
          boost::mpl::push_front<typename P::second, typename P::first>
        {};
      };
    }
  }
}

#endif

