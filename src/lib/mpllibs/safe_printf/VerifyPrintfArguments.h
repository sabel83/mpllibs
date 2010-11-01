#ifndef MPLLIBS_PRINTF_VERIFY_PRINTF_ARGUMENTS_H
#define MPLLIBS_PRINTF_VERIFY_PRINTF_ARGUMENTS_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/PrintfParser.h>
#include <mpllibs/safe_printf/VerifyPrintfArgumentsImpl.h>

#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    template <class F, class ArgTypes>
    struct VerifyPrintfArguments :
      mpllibs::safe_printf::VerifyPrintfArgumentsImpl<
        boost::mpl::apply<mpllibs::safe_printf::PrintfParser, F>,
        ArgTypes
      >
    {};
  }
}

#endif

