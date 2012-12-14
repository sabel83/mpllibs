#ifndef MPLLIBS_METAMONAD_OVERLOADING_ERROR_HPP
#define MPLLIBS_METAMONAD_OVERLOADING_ERROR_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_tag.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct overloading_error_tag : tmp_tag<overloading_error_tag> {};
  }
}

#endif

