#ifndef MPLLIBS_METAMONAD_EXCEPTION_CORE_HPP
#define MPLLIBS_METAMONAD_EXCEPTION_CORE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/data.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_DATA(exception, 0, ((exception, 1)));
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  mpllibs::metamonad::exception,
  "exception"
)

#endif

