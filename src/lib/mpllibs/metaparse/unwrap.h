#ifndef MPLLIBS_PARSER_UNWRAP_H
#define MPLLIBS_PARSER_UNWRAP_H

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

namespace mpllibs
{
  namespace metaparse
  {
    template <class w>
    struct unwrap
    {
      typedef typename w::type::wrapped_value type;
    };
  }
}

#endif

