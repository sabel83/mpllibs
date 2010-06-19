#ifndef MPLLIBS_PARSER_RETURN_H
#define MPLLIBS_PARSER_RETURN_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/pair.h>

#include <boost/mpl/identity.hpp>

namespace mpllibs
{
  namespace parser
  {
    template <class c>
    struct return_
    {
      template <class S>
      struct apply : boost::mpl::identity<mpllibs::util::pair<c, S> > {};
    };
  }
}

#endif

