#ifndef MPLLIBS_METAMONAD_V1_FWD_IS_TAG_HPP
#define MPLLIBS_METAMONAD_V1_FWD_IS_TAG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// For boost::mpl::na
#include <boost/mpl/vector.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class T, class E = boost::mpl::na>
      struct is_tag;
    }
  }
}

#endif

