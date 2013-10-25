#ifndef MPLLIBS_SAFE_PRINTF_IMPL_NONEMPTY_HPP
#define MPLLIBS_SAFE_PRINTF_IMPL_NONEMPTY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/impl/pop_expected.hpp>
#include <mpllibs/safe_printf/impl/verify_argument.hpp>

#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    namespace impl
    {
      template <class Expected, class Actual>
      struct valid_arguments;

      template <class E, class A>
      struct nonempty :
        boost::mpl::eval_if<
          typename verify_argument<
            boost::mpl::front<E>,
            boost::mpl::front<A>
          >::type,
          valid_arguments<pop_expected<E>, boost::mpl::pop_front<A> >,
          boost::mpl::false_
        >
      {};
    }
  }
}

#endif

