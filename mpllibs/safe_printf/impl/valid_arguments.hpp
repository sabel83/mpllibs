#ifndef MPLLIBS_SAFE_PRINTF_IMPL_VALID_ARGUMENTS_HPP
#define MPLLIBS_SAFE_PRINTF_IMPL_VALID_ARGUMENTS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/impl/nonempty.hpp>

#include <boost/mpl/bool.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    namespace impl
    {
      // Lazy function
      template <class Expected, class Actual>
      struct valid_arguments
      {
      private:
        typedef typename Expected::type ExpectedValue;
        typedef typename Actual::type ActualValue;
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
}

#endif

