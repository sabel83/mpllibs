#ifndef MPLLIBS_METAMONAD_EXCEPTION_CORE_HPP
#define MPLLIBS_METAMONAD_EXCEPTION_CORE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tag_tag.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_DEFINE_TAG(exception_tag)
  
    template <class Data>
    struct exception
    {
      typedef exception_tag tag;
      typedef exception type;

      typedef Data data;
    };
  }
}

#endif

