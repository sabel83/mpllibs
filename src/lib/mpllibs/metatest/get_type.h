#ifndef MPLLIBS_TEST_GET_TYPE_H
#define MPLLIBS_TEST_GET_TYPE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/has_type.h>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

namespace mpllibs
{
  namespace metatest
  {
    template <class T, class Default>
    struct get_type :
      boost::mpl::eval_if<
        typename mpllibs::metatest::has_type<T>::type,
        T,
        boost::mpl::identity<Default>
      >
    {};
  }
}

#endif

