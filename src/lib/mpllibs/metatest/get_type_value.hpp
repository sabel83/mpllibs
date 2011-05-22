#ifndef MPLLIBS_TEST_GET_TYPE_VALUE_H
#define MPLLIBS_TEST_GET_TYPE_VALUE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/get_value.hpp>
#include <mpllibs/metatest/get_type.hpp>

#include <boost/mpl/identity.hpp>

namespace mpllibs
{
  namespace metatest
  {
    template <class T, class Default>
    struct get_type_value :
      get_value<
        typename get_type<T, boost::mpl::identity<Default> >::type,
        Default
      >
    {};
  }
}

#endif

