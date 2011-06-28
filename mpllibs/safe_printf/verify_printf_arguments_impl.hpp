#ifndef MPLLIBS_SAFE_PRINTF_VERIFY_PRINTF_ARGUMENTS_IMPL_HPP
#define MPLLIBS_SAFE_PRINTF_VERIFY_PRINTF_ARGUMENTS_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/pop_expected.hpp>
#include <mpllibs/safe_printf/verify_argument.hpp>

#include <boost/mpl/bool.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    // Lazy function
    template <class Expected, class Actual>
    struct verify_printf_arguments_impl
    {
    private:
      typedef typename Expected::type ExpectedValue;
      typedef typename Actual::type ActualValue;
    
      template <class E, class A>
      struct nonempty :
        boost::mpl::eval_if<
          typename verify_argument<
            boost::mpl::front<E>,
            boost::mpl::front<A>
          >::type,
          verify_printf_arguments_impl<
            pop_expected<E>,
            boost::mpl::pop_front<A>
          >,
          boost::mpl::false_
        >
      {};

    public:
      typedef
        typename boost::mpl::eval_if<
          typename boost::mpl::empty<ExpectedValue>::type,
          boost::mpl::empty<ActualValue>,
          boost::mpl::eval_if<
            typename boost::mpl::empty<ActualValue>::type,
            boost::mpl::false_,
            nonempty<ExpectedValue, ActualValue>
          >
        >::type
        type;
    };
  }
}

#endif

