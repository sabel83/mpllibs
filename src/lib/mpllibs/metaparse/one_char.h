#ifndef MPLLIBS_PARSER_ONE_CHAR_H
#define MPLLIBS_PARSER_ONE_CHAR_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/nothing.h>

#include <mpllibs/metaparse/util/make_pair.h>

#include <boost/mpl/empty.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    struct one_char
    {
      template <class S>
      struct apply :
        boost::mpl::eval_if<
          typename boost::mpl::empty<S>::type,
          nothing,
          mpllibs::metaparse::util::make_pair<
            boost::mpl::front<S>,
            boost::mpl::pop_front<S>
          >
        >
      {};
    };
  }
}

#endif

