#ifndef MPLLIBS_METAMONAD_V1_OVERLOADING_ERROR_TAG_HPP
#define MPLLIBS_METAMONAD_V1_OVERLOADING_ERROR_TAG_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/overloading_error_tag.hpp>
#include <mpllibs/metamonad/v1/tmp_tag.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      struct overloading_error_tag : tmp_tag<overloading_error_tag> {};
    }
  }
}

#endif

