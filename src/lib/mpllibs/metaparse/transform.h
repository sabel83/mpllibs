#ifndef MPLLIBS_PARSER_TRANSFORM_H
#define MPLLIBS_PARSER_TRANSFORM_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/nothing.h>

#include <mpllibs/metaparse/util/pair.h>
#include <mpllibs/metaparse/util/make_pair.h>
#include <mpllibs/metaparse/util/compose.h>
#include <mpllibs/metaparse/util/lazy_equal_to.h>
#include <mpllibs/metaparse/util/lazy_eval_if.h>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/quote.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p, class t>
    struct transform
    {
      template <class S>
      struct apply :
        boost::mpl::eval_if<
          mpllibs::metaparse::util::lazy_equal_to<
            boost::mpl::apply<p, S>,
            mpllibs::metaparse::nothing
          >,
          mpllibs::metaparse::nothing,
          mpllibs::metaparse::util::make_pair<
            boost::mpl::apply<
              mpllibs::metaparse::util::compose<
                t,
                boost::mpl::quote1<boost::mpl::first>,
                p
              >,
              S
            >,
            boost::mpl::apply<
              mpllibs::metaparse::util::compose<
                boost::mpl::quote1<boost::mpl::second>,
                p
              >,
              S
            >
          >
        >
      {};
    };
  }
}

#endif

