// Copyright Abel Sinkovics (abel@sinkovics.hu)  2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// no include guard - this header can be included multiple times

#ifndef MPLLIBS_DEFINE_PRINTF_NAME
#  error MPLLIBS_DEFINE_PRINTF_NAME has to be defined
#endif

#ifndef MPLLIBS_DEFINE_PRINTF_HAS_ARGS
#  error MPLLIBS_DEFINE_PRINTF_HAS_ARGS has to be defined
#endif

#if MPLLIBS_DEFINE_PRINTF_HAS_ARGS
#  ifndef MPLLIBS_DEFINE_PRINTF_ARGS
#    error MPLLIBS_DEFINE_PRINTF_ARGS has to be defined
#  endif
#else
#  ifdef MPLLIBS_DEFINE_PRINTF_ARGS
#    error MPLLIBS_DEFINE_PRINTF_ARGS should not be defined
#  endif
#endif

