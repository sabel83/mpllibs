#ifndef MPLLIBS_METAMONAD_V1_FWD_CALCULATED_VALUE_HPP
#define MPLLIBS_METAMONAD_V1_FWD_CALCULATED_VALUE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/no_tag_for_tmp_value.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class T, class ValueType, class Tag=impl::no_tag_for_tmp_value>
      struct calculated_value;
    }
  }
}

#endif

