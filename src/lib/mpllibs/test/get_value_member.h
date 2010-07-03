#ifndef MPLLIBS_TEST_GET_VALUE_MEMBER_H
#define MPLLIBS_TEST_GET_VALUE_MEMBER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/test/has_value_member.h>

#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace test
  {
    template <class T, class Default>
    struct get_value_member :
      boost::mpl::eval_if<
        typename mpllibs::test::has_value_member<T, bool>::type,
        T,
        Default
      >
    {};
  }
}

#endif

