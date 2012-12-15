#ifndef MPLLIBS_METAMONAD_TMP_VALUE_HPP
#define MPLLIBS_METAMONAD_TMP_VALUE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <mpllibs/metamonad/returns.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct no_tag_for_tmp_value;

    template <class T, class Tag = no_tag_for_tmp_value>
    struct tmp_value : tmp_value<T, no_tag_for_tmp_value>
    {
      typedef Tag tag;
    };

    template <class T>
    struct tmp_value<T, no_tag_for_tmp_value> : returns<T> {};
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  mpllibs::metamonad::tmp_value,
  "tmp_value"
)

#endif

