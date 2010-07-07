#ifndef MPLLIBS_PRINTF_VERIFY_PRINTF_ARGUMENTS_H
#define MPLLIBS_PRINTF_VERIFY_PRINTF_ARGUMENTS_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/printf/PrintfParser.h>
#include <mpllibs/printf/VerifyPrintfArgumentsImpl.h>

#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace printf
  {
    template <class F, class ArgTypes>
    struct VerifyPrintfArguments :
      VerifyPrintfArgumentsImpl<
        boost::mpl::apply<PrintfParser, F>,
        boost::mpl::identity<ArgTypes>
      >
    {};
  }
}

#endif

