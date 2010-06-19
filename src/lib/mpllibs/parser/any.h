#ifndef MPLLIBS_PARSER_ANY_H
#define MPLLIBS_PARSER_ANY_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/one_of.h>
#include <mpllibs/parser/return.h>
#include <mpllibs/parser/transform.h>
#include <mpllibs/parser/sequence.h>

#include <mpllibs/util/cons.h>

#include <boost/mpl/list.hpp>

namespace mpllibs
{
  namespace parser
  {
    template <class p>
    struct any :
      mpllibs::parser::one_of<
        mpllibs::parser::transform<
          mpllibs::parser::sequence<p, mpllibs::parser::any<p> >,
          mpllibs::util::cons
        >,
        mpllibs::parser::return_<boost::mpl::list<> >
      >
    {};
  }
}

#endif

