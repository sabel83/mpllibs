#ifndef MPLLIBS_METAMONAD_V1_MAKE_TMP_VALUE_HPP
#define MPLLIBS_METAMONAD_V1_MAKE_TMP_VALUE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/make_tmp_value.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class T, class Tag>
      struct make_tmp_value : T
      {
        typedef make_tmp_value type;
        typedef Tag tag;
      };

      template <class T>
      struct make_tmp_value<T, impl::no_tag_for_tmp_value> : T
      {
        typedef make_tmp_value type;
      };
    }
  }
}

#endif

