#ifndef MPLLIBS_SAFE_PRINTF_V1_FPRINTF_HPP
#define MPLLIBS_SAFE_PRINTF_V1_FPRINTF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/v1/fwd/fprintf.hpp>

#include <cstdio>

#define MPLLIBS_DEFINE_PRINTF_NAME fprintf
#define MPLLIBS_DEFINE_PRINTF_HAS_ARGS 1
#define MPLLIBS_DEFINE_PRINTF_ARGS (FILE*)
#  include <mpllibs/safe_printf/v1/impl/define_printf.hpp>
#undef MPLLIBS_DEFINE_PRINTF_ARGS
#undef MPLLIBS_DEFINE_PRINTF_HAS_ARGS
#undef MPLLIBS_DEFINE_PRINTF_NAME

#endif

