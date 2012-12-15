#ifndef MPLLIBS_METAMONAD_RETURNS_HPP
#define MPLLIBS_METAMONAD_RETURNS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

namespace mpllibs
{
  namespace metamonad
  {
    template <class T>
    struct returns
    {
      typedef T type;
    };
  }
}

#endif

