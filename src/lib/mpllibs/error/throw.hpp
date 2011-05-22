#ifndef MPLLIBS_ERROR_THROW_H
#define MPLLIBS_ERROR_THROW_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/exception.hpp>

namespace mpllibs
{
  namespace error
  {
    #ifdef THROW
      #error THROW already defined
    #endif
    #define THROW mpllibs::error::exception
  }
}


#endif

