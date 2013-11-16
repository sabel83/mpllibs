#ifndef MPLLIBS_SAFE_PRINTF_VERIFY_PRINTF_ARGUMENTS_HPP
#define MPLLIBS_SAFE_PRINTF_VERIFY_PRINTF_ARGUMENTS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/impl/matches.hpp>
#include <mpllibs/safe_printf/expected_types.hpp>

#include <mpllibs/metamonad/metafunction.hpp>

#include <boost/mpl/equal.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    MPLLIBS_METAFUNCTION(valid_arguments, (F)(ArgTypes))
    ((
      boost::mpl::equal<
        typename expected_types<F>::type,
        typename ArgTypes::type,
        impl::matches<>
      >
    ));
  }
}

#endif

