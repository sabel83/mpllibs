#ifndef MPLLIBS_PARSER_WRAP_H
#define MPLLIBS_PARSER_WRAP_H

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

namespace mpllibs
{
  namespace metaparse
  {
    template <class tag_type>
    struct wrap
    {
      template <class value>
      struct apply
      {
        typedef tag_type tag;
        typedef apply type;
        
        typedef value wrapped_value;
      };
    };
  }
}

#endif

