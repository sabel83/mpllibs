#ifndef MPLLIBS_METAPARSE_V1_RETURN__HPP
#define MPLLIBS_METAPARSE_V1_RETURN__HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/accept_tag.hpp>
#include <mpllibs/metaparse/v1/get_result.hpp>

#include <mpllibs/metamonad/tmp_tag.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      template <class C>
      struct return_
      {
        typedef return_ type;
        
        template <class S, class Pos>
        struct apply
        {
          typedef accept_tag tag;
          typedef apply type;
  
          typedef C result;
          typedef S remaining;
          typedef Pos source_position;
        };
      };
    }
  }
}

#endif

