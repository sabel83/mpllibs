#ifndef MPLLIBS_PARSER_TOKEN_H
#define MPLLIBS_PARSER_TOKEN_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/spaces.h>
#include <mpllibs/metaparse/first_of.h>
#include <mpllibs/metaparse/one_of.h>
#include <mpllibs/metaparse/empty.h>

#include <boost/mpl/void.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p>
    struct token :
      mpllibs::metaparse::first_of<
        p,
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::empty<boost::mpl::void_>,
          mpllibs::metaparse::spaces
        >
      >
    {};
  }
}

#endif

