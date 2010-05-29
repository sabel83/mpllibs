#ifndef MPLLIBS_PRINTF_VERIFY_ARGUMENT_H
#define MPLLIBS_PRINTF_VERIFY_ARGUMENT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/printf/VerifyArgumentImpl.h>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/or.hpp>

namespace mpllibs
{
  namespace printf
  {
    // This function is lazy
    template <class Expected, class Actual>
    struct VerifyArgument :
      boost::mpl::eval_if<
        typename boost::mpl::or_<
          typename Expected::type::first,
          typename Expected::type::second::first
        >::type,
        VerifyArgumentImpl<
          mpllibs::printf::ExpectUnsignedInteger,
          typename Actual::type
        >,
        VerifyArgumentImpl<
          typename Expected::type::second::second,
          typename Actual::type
        >
      >
    {};
  }
}

#endif

