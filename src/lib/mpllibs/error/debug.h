#ifndef MPLLIBS_ERROR_DEBUG_H
#define MPLLIBS_ERROR_DEBUG_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream.h>

#include <iostream>

namespace mpllibs
{
  namespace metatest
  {
    template <class e>
    struct debug
    {
      debug()
      {
        mpllibs::metatest::to_stream<typename e::type>::run(std::cout)
          << std::endl;
        exit(0);
      }
    };
  }
}

#endif

