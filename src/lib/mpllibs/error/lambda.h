// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#ifndef MPLLIBS_ERROR_LAMBDA_H
#define MPLLIBS_ERROR_LAMBDA_H

#include <mpllibs/error/let.h>

namespace mpllibs
{
  namespace error
  {
    template <class arg_name, class f>
    struct lambda
    {
      typedef mpllibs::error::lambda<arg_name, f> type;

      template <class t>
      struct apply : mpllibs::error::let<arg_name, t, f>::type {};
    };
  }
}

#endif

