#ifndef MPLLIBS_UTIL_IS_NOTHING_H
#define MPLLIBS_UTIL_IS_NOTHING_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/nothing.h>

#include <boost/mpl/equal_to.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      template <class t>
      struct is_nothing :
        boost::mpl::equal_to<mpllibs::metaparse::nothing, typename t::type>
      {};
    }
  }
}

#endif

