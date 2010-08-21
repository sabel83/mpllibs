#ifndef MPLLIBS_TEST_HAS_TYPE_VALUE_MEMBER_H
#define MPLLIBS_TEST_HAS_TYPE_VALUE_MEMBER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/test/has_value_member.h>
#include <mpllibs/test/get_type.h>

namespace mpllibs
{
  namespace test
  {
    template <class T, class ValueType>
    struct has_type_value_member :
      mpllibs::test::has_value_member<
        typename mpllibs::test::get_type<T, int>::type,
        ValueType
      >
    {};
  }
}

#endif

