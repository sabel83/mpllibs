#ifndef SAFE_PRINTF_VERIFY_ARGUMENT_HPP
#define SAFE_PRINTF_VERIFY_ARGUMENT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "verify_argument_impl.hpp"

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/or.hpp>

#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/at.hpp>

namespace safe
{
  // This function is lazy
  template <class Expected, class Actual>
  struct verify_argument :
    boost::mpl::eval_if<
      typename boost::mpl::or_<
        typename boost::mpl::front<typename Expected::type>::type,
        typename boost::mpl::at_c<typename Expected::type, 1>::type
      >::type,
      verify_argument_impl<expect_unsigned_integer, typename Actual::type>,
      verify_argument_impl<
        typename boost::mpl::back<typename Expected::type>::type,
        typename Actual::type
      >
    >
  {};
}

#endif

