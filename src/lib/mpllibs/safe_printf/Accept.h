#ifndef MPLLIBS_PRINTF_ACCEPT_H
#define MPLLIBS_PRINTF_ACCEPT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/identity.hpp>
#include <boost/mpl/bool.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    typedef boost::mpl::identity<boost::mpl::true_> Accept;
  }
}

#endif

