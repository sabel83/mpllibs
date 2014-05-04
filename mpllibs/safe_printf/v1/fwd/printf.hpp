#ifndef MPLLIBS_SAFE_PRINTF_V1_FWD_PRINTF_HPP
#define MPLLIBS_SAFE_PRINTF_V1_FWD_PRINTF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cstdio>

#define MPLLIBS_DEFINE_PRINTF_NAME printf
#define MPLLIBS_DEFINE_PRINTF_HAS_ARGS 0
#  include <mpllibs/safe_printf/v1/impl/fwd_define_printf.hpp>
#undef MPLLIBS_DEFINE_PRINTF_HAS_ARGS
#undef MPLLIBS_DEFINE_PRINTF_NAME

// Backward compatibility
#include <mpllibs/safe_printf/v1/fwd/fprintf.hpp>
#include <mpllibs/safe_printf/v1/fwd/sprintf.hpp>

#endif

