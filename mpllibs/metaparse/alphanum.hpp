#ifndef MPLLIBS_METAPARSE_ALPHANUM_HPP
#define MPLLIBS_METAPARSE_ALPHANUM_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/digit.hpp>
#include <mpllibs/metaparse/letter.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    typedef one_of<letter, digit> alphanum;
  }
}

#endif

