#ifndef MPLLIBS_METAMONAD_THROW_HPP
#define MPLLIBS_METAMONAD_THROW_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/exception_core.hpp>

#ifdef MPLLIBS_THROW
  #error MPLLIBS_THROW already defined
#endif
#define MPLLIBS_THROW mpllibs::metamonad::exception

#endif

