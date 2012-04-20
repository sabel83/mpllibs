#ifndef MPLLIBS_METATEST_HAS_TYPE_VALUE_HPP
#define MPLLIBS_METATEST_HAS_TYPE_VALUE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <mpllibs/metatest/has_value.hpp>
#include <mpllibs/metatest/get_type.hpp>

namespace mpllibs
{
  namespace metatest
  {
    template <class T, class ValueType>
    struct has_type_value :
      has_value<typename get_type<T, int>::type, ValueType>
    {};
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  mpllibs::metatest::has_type_value,
  "has_type_value"
)

#endif

