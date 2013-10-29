#ifndef MPLLIBS_METAMONAD_FAIL_WITH_TYPE_HPP
#define MPLLIBS_METAMONAD_FAIL_WITH_TYPE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

namespace mpllibs
{
  namespace metamonad
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

#endif

