#ifndef MPLLIBS_METAMONAD_V1_TMP_VALUE_HPP
#define MPLLIBS_METAMONAD_V1_TMP_VALUE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/tmp_value.hpp>
#include <mpllibs/metamonad/v1/returns.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class T, class Tag>
      struct tmp_value : tmp_value<T, impl::no_tag_for_tmp_value>
      {
        typedef Tag tag;
      };

      template <class T>
      struct tmp_value<T, impl::no_tag_for_tmp_value> : returns<T> {};
    }
  }
}

#endif

