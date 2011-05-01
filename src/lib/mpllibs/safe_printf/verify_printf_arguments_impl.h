#ifndef MPLLIBS_VERIFY_PRINTF_ARGUMENTS_IMPL_H
#define MPLLIBS_VERIFY_PRINTF_ARGUMENTS_IMPL_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/pop_expected.h>
#include <mpllibs/safe_printf/verify_argument.h>

#include <mpllibs/metaparse/util/lazy_eval_if.h>

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
    struct verify_printf_arguments_impl :
      boost::mpl::eval_if<
        typename boost::mpl::empty<typename Expected::type>::type,
        boost::mpl::empty<typename Actual::type>,
        boost::mpl::eval_if<
          typename boost::mpl::empty<typename Actual::type>::type,
          boost::mpl::false_,
          mpllibs::metaparse::util::lazy_eval_if<
            verify_argument<
              boost::mpl::front<typename Expected::type>,
              boost::mpl::front<typename Actual::type>
            >,
            verify_printf_arguments_impl<
              pop_expected<typename Expected::type>,
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

