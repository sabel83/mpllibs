#ifndef MPLLIBS_METAMONAD_MAKE_TMP_VALUE_HPP
#define MPLLIBS_METAMONAD_MAKE_TMP_VALUE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_value.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class T, class Tag = no_tag_for_tmp_value>
    struct make_tmp_value : T
    {
      typedef make_tmp_value type;
      typedef Tag tag;
    };

    template <class T>
    struct make_tmp_value<T, no_tag_for_tmp_value> : T
    {
      typedef make_tmp_value type;
    };
  }
}

#endif

