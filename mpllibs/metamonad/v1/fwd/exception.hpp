#ifndef MPLLIBS_METAMONAD_V1_FWD_EXCEPTION_HPP
#define MPLLIBS_METAMONAD_V1_FWD_EXCEPTION_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/void.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class Reason = boost::mpl::void_>
      struct exception;
    }
  }
}

#endif

