#ifndef MPLLIBS_PRINTF_VERIFY_ARGUMENT_H
#define MPLLIBS_PRINTF_VERIFY_ARGUMENT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/VerifyArgumentImpl.h>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/or.hpp>

#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    // This function is lazy
    template <class Expected, class Actual>
    struct VerifyArgument :
      boost::mpl::eval_if<
        typename boost::mpl::or_<
          typename boost::mpl::front<typename Expected::type>::type,
          typename boost::mpl::front<
            typename boost::mpl::back<typename Expected::type>::type
          >::type
        >::type,
        VerifyArgumentImpl<
          mpllibs::safe_printf::ExpectUnsignedInteger,
          typename Actual::type
        >,
        VerifyArgumentImpl<
          typename boost::mpl::back<
            typename boost::mpl::back<typename Expected::type>::type
          >::type,
          typename Actual::type
        >
      >
    {};
  }
}

#endif

