// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#ifndef MPLLIBS_ERROR_LETREC_H
#define MPLLIBS_ERROR_LETREC_H

#include <mpllibs/error/let.h>

namespace mpllibs
{
  namespace error
  {
    template <class a, class e1, class e2>
    struct letrec :
      mpllibs::error::let<a, mpllibs::error::letrec<a, e1, e1>, e2>
    {};
  }
}

#endif

