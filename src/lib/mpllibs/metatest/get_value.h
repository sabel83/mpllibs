#ifndef MPLLIBS_TEST_GET_VALUE_H
#define MPLLIBS_TEST_GET_VALUE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/has_value.h>

#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace metatest
  {
    template <class T, class Default>
    struct get_value :
      boost::mpl::eval_if<
        typename mpllibs::metatest::has_value<T, bool>::type,
        T,
        Default
      >
    {};
  }
}

#endif

