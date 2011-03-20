#ifndef MPLLIBS_PARSER_ITERATE_C_H
#define MPLLIBS_PARSER_ITERATE_C_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/iterate.h>

#include <boost/mpl/int.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p, int n>
    struct iterate_c : mpllibs::metaparse::iterate<p, boost::mpl::int_<n> > {};
  }
}

#endif

