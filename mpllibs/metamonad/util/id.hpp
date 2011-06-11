#ifndef MPLLIBS_ERROR_UTIL_ID_H
#define MPLLIBS_ERROR_UTIL_ID_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

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

#endif

