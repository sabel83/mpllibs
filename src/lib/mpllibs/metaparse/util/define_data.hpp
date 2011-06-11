#ifndef MPLLIBS_METAPARSE_UTIL_DEFINE_DATA_HPP
#define MPLLIBS_METAPARSE_UTIL_DEFINE_DATA_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifdef MPLLIBS_METAPARSE_DEFINE_DATA
  #error MPLLIBS_METAPARSE_DEFINE_DATA already defined
#endif
#define MPLLIBS_METAPARSE_DEFINE_DATA(name) \
  struct name \
  { \
    typedef name type; \
  }

#endif

