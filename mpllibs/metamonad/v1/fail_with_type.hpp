#ifndef MPLLIBS_METAMONAD_V1_FAIL_WITH_TYPE_HPP
#define MPLLIBS_METAMONAD_V1_FAIL_WITH_TYPE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/fail_with_type.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        template <class T>
        struct FAIL_WITH_TYPE__________________________________ {};
      }

      template <class T>
      void fail_with_type()
      {
        impl::FAIL_WITH_TYPE__________________________________<T>::f();
      }
    }
  }
}

#endif

