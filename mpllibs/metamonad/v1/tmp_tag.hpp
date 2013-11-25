#ifndef MPLLIBS_METAMONAD_V1_TMP_TAG_HPP
#define MPLLIBS_METAMONAD_V1_TMP_TAG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/tmp_tag.hpp>
#include <mpllibs/metamonad/v1/fwd/tag_tag.hpp>
#include <mpllibs/metamonad/v1/tmp_value.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      // MPLLIBS_V1_METAFUNCTION depends on it
      template <class T>
      struct tmp_tag : tmp_value<T, tag_tag> {};
    }
  }
}

#endif

