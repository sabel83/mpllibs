#ifndef MPLLIBS_PARSER_ANY_H
#define MPLLIBS_PARSER_ANY_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/one_of.h>
#include <mpllibs/metaparse/return.h>
#include <mpllibs/metaparse/transform.h>
#include <mpllibs/metaparse/sequence.h>

#include <mpllibs/util/cons.h>

#include <boost/mpl/list.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p>
    struct any :
      mpllibs::metaparse::one_of<
        mpllibs::metaparse::transform<
          mpllibs::metaparse::sequence<p, mpllibs::metaparse::any<p> >,
          mpllibs::util::cons
        >,
        mpllibs::metaparse::return_<boost::mpl::list<> >
      >
    {};
  }
}

#endif

