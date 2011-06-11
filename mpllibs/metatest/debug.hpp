#ifndef MPLLIBS_METATEST_DEBUG_HPP
#define MPLLIBS_METATEST_DEBUG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metatest
  {
    template <class E>
    struct debug
    {
      debug()
      {
        mpllibs::metatest::to_stream<typename E::type>::run(std::cout)
          << std::endl;
        exit(0);
      }
    };
  }
}

#endif

