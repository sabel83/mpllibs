#ifndef MPLLIBS_ERROR_LAMBDA_H
#define MPLLIBS_ERROR_LAMBDA_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/let.hpp>

namespace mpllibs
{
  namespace error
  {
    template <class ArgName, class F>
    struct lambda
    {
      typedef lambda type;

      template <class T>
      struct apply : let<ArgName, T, F>::type {};
    };
  }
}

#endif

