#ifndef MPLLIBS_METAMONAD_V1_FWD_IS_SAME_HPP
#define MPLLIBS_METAMONAD_V1_FWD_IS_SAME_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/is_same_no_arg.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class A = impl::is_same_no_arg, class B = impl::is_same_no_arg>
      struct is_same;
    }
  }
}

#endif

