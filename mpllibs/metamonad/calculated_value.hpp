#ifndef MPLLIBS_METAMONAD_CALCULATED_VALUE_HPP
#define MPLLIBS_METAMONAD_CALCULATED_VALUE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_value.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class T, class ValueType, class Tag = no_tag_for_tmp_value>
    struct calculated_value : tmp_value<T, Tag>
    {
      static const ValueType value;
    };

    template <class T, class ValueType, class Tag>
    const ValueType calculated_value<T, ValueType, Tag>::value =
      T::get_value();
  }
}

#endif

