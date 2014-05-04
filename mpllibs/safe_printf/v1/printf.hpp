#ifndef MPLLIBS_SAFE_PRINTF_V1_PRINTF_HPP
#define MPLLIBS_SAFE_PRINTF_V1_PRINTF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/v1/fwd/printf.hpp>

#include <cstdio>

#define MPLLIBS_DEFINE_PRINTF_NAME printf
#define MPLLIBS_DEFINE_PRINTF_HAS_ARGS 0
#  include <mpllibs/safe_printf/v1/impl/define_printf.hpp>
#undef MPLLIBS_DEFINE_PRINTF_HAS_ARGS
#undef MPLLIBS_DEFINE_PRINTF_NAME

// Backward compatibility
#include <mpllibs/safe_printf/v1/fprintf.hpp>
#include <mpllibs/safe_printf/v1/sprintf.hpp>

#endif

