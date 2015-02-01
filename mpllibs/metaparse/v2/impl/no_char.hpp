#ifndef MPLLIBS_METAPARSE_V2_IMPL_NO_CHAR_HPP
#define MPLLIBS_METAPARSE_V2_IMPL_NO_CHAR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cstdio>

#ifdef MPLLIBS_NO_CHAR
#  error MPLLIBS_NO_CHAR already defined
#endif
#define MPLLIBS_NO_CHAR EOF

#endif

