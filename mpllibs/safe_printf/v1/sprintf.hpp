#ifndef MPLLIBS_SAFE_PRINTF_V1_SPRINTF_HPP
#define MPLLIBS_SAFE_PRINTF_V1_SPRINTF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/v1/fwd/sprintf.hpp>

#include <cstdio>

#define MPLLIBS_DEFINE_PRINTF_NAME sprintf
#define MPLLIBS_DEFINE_PRINTF_HAS_ARGS 1
#define MPLLIBS_DEFINE_PRINTF_ARGS (char*)
#  include <mpllibs/safe_printf/v1/impl/define_printf.hpp>
#undef MPLLIBS_DEFINE_PRINTF_ARGS
#undef MPLLIBS_DEFINE_PRINTF_HAS_ARGS
#undef MPLLIBS_DEFINE_PRINTF_NAME

#endif

