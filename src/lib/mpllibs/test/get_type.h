#ifndef MPLLIBS_TEST_GET_TYPE_H
#define MPLLIBS_TEST_GET_TYPE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/test/has_type.h>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

namespace mpllibs
{
  namespace test
  {
    template <class T, class Default>
    struct get_type
    {
      template <class U>
      struct no_check
      {
        typedef typename U::type type;
      };
      
      typedef
        typename boost::mpl::eval_if<
          typename mpllibs::test::has_type<T>::type,
          typename
            mpllibs::test::get_type<T, Default>::template no_check<T>,
          boost::mpl::identity<Default>
        >::type
        type;
    };
  }
}

#endif

