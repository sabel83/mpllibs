#ifndef MPLLIBS_PARSER_EXCEPT_H
#define MPLLIBS_PARSER_EXCEPT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/nothing.h>

#include <mpllibs/util/make_pair.h>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/identity.hpp>

namespace mpllibs
{
  namespace parser
  {
    template <class p, class result>
    struct except
    {
      template <class S>
      struct apply :
        boost::mpl::eval_if<
          typename boost::mpl::equal_to<
            typename p::template apply<S>::type,
            mpllibs::parser::nothing
          >::type,
          mpllibs::util::make_pair<boost::mpl::identity<result>, S>,
          mpllibs::parser::nothing
        >
      {};
    };
  }
}

#endif

