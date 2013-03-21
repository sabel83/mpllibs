#ifndef MPLLIBS_METAMONAD_TMP_TAG_HPP
#define MPLLIBS_METAMONAD_TMP_TAG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_value.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct tag_tag;

    // MPLLIBS_METAFUNCTION depends on it
    template <class T>
    struct tmp_tag : tmp_value<T, tag_tag> {};
  }
}

#endif

