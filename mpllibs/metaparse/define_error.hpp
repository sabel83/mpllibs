#ifndef MPLLIBS_METAPARSE_DEFINE_ERROR_HPP
#define MPLLIBS_METAPARSE_DEFINE_ERROR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <string>

#ifdef MPLLIBS_DEFINE_ERROR
  #error MPLLIBS_DEFINE_ERROR already defined
#endif
#define MPLLIBS_DEFINE_ERROR(name, msg) \
  struct name \
  { \
    typedef name type; \
    static std::string get_value() \
    { \
      return msg; \
    } \
  }

#endif

