#ifndef MPLLIBS_PARSER_EXCEPT_H
#define MPLLIBS_PARSER_EXCEPT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/nothing.h>

#include <mpllibs/metaparse/util/make_pair.h>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p, class result>
    struct except
    {
      template <class S>
      struct apply :
        boost::mpl::eval_if<
          typename boost::mpl::equal_to<
            typename boost::mpl::apply<p, S>::type,
            mpllibs::metaparse::nothing
          >::type,
          mpllibs::metaparse::util::make_pair<boost::mpl::identity<result>, S>,
          mpllibs::metaparse::nothing
        >
      {};
    };
  }
}

#endif

