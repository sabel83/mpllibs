#ifndef MPLLIBS_METAMONAD_META_ATOM_HPP
#define MPLLIBS_METAMONAD_META_ATOM_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>

#ifdef MPLLIBS_DEFINE_META_ATOM
  #error MPLLIBS_DEFINE_META_ATOM already defined
#endif
#define MPLLIBS_DEFINE_META_ATOM(tag_type, name) \
  struct name \
  { \
    typedef name type; \
    typedef tag_type tag; \
    \
    struct to_stream \
    { \
      static std::ostream& run(std::ostream& o) \
      { \
        return o << #name; \
      } \
    }; \
  }

#endif

