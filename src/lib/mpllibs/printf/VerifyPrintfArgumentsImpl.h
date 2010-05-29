#ifndef MPLLIBS_VERIFY_PRINTF_ARGUMENTS_IMPL_H
#define MPLLIBS_VERIFY_PRINTF_ARGUMENTS_IMPL_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/printf/PopExpected.h>
#include <mpllibs/printf/VerifyArgument.h>

#include <boost/mpl/bool.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>

namespace mpllibs
{
  namespace printf
  {
    // Lazy function
    template <class Expected, class Actual>
    struct VerifyPrintfArgumentsImpl :
      boost::mpl::eval_if<
        typename boost::mpl::empty<typename Expected::type>::type,
        boost::mpl::empty<typename Actual::type>,
        boost::mpl::eval_if<
          typename boost::mpl::empty<typename Actual::type>::type,
          boost::mpl::false_,
          mpllibs::util::lazy_eval_if<
            VerifyArgument<
              boost::mpl::front<typename Expected::type>,
              boost::mpl::front<typename Actual::type>
            >,
            VerifyPrintfArgumentsImpl<
              PopExpected<typename Expected::type>,
              boost::mpl::pop_front<typename Actual::type>
            >,
            boost::mpl::false_
          >
        >
      >
    {};
  }
}

#endif

