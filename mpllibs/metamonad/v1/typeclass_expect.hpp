#ifndef MPLLIBS_METAMONAD_V1_TYPECLASS_EXPECT_HPP
#define MPLLIBS_METAMONAD_V1_TYPECLASS_EXPECT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/exception.hpp>
#include <mpllibs/metamonad/v1/invalid_typeclass.hpp>

#ifdef MPLLIBS_V1_TYPECLASS_EXPECT
#  error MPLLIBS_V1_TYPECLASS_EXPECT already defined
#endif
#define MPLLIBS_V1_TYPECLASS_EXPECT(name) \
  typedef \
    mpllibs::metamonad::v1::exception< \
      mpllibs::metamonad::v1::invalid_typeclass \
    > \
    name

#endif

