#ifndef MPLLIBS_METAPARSE_FAIL_TAG_HPP
#define MPLLIBS_METAPARSE_FAIL_TAG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_tag.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    struct fail_tag : mpllibs::metamonad::tmp_tag<fail_tag> {};
  }
}

#endif


