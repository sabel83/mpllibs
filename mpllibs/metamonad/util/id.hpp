#ifndef MPLLIBS_ERROR_UTIL_ID_HPP
#define MPLLIBS_ERROR_UTIL_ID_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_fwd.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace util
    {
      template <class T>
      struct id
      {
        typedef T type;
      };
    }
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, mpllibs::metamonad::util::id, "id")

#endif

