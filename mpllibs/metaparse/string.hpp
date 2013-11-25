#ifndef MPLLIBS_METAPARSE_STRING_HPP
#define MPLLIBS_METAPARSE_STRING_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/string.hpp>
#include <mpllibs/metaparse/string_tag.hpp>

#ifdef MPLLIBS_STRING
#  error MPLLIBS_STRING already defined
#endif
#define MPLLIBS_STRING MPLLIBS_V1_STRING

namespace mpllibs
{
  namespace metaparse
  {
    using v1::string;
  }
}

#endif

