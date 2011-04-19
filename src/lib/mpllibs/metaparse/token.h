#ifndef MPLLIBS_PARSER_TOKEN_H
#define MPLLIBS_PARSER_TOKEN_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/space.h>
#include <mpllibs/metaparse/any.h>
#include <mpllibs/metaparse/first_of.h>

#include <boost/mpl/void.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p>
    struct token :
      mpllibs::metaparse::first_of<
        p,
        mpllibs::metaparse::any<mpllibs::metaparse::space>
      >
    {};
  }
}

#endif

