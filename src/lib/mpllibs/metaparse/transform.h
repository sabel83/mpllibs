#ifndef MPLLIBS_PARSER_TRANSFORM_H
#define MPLLIBS_PARSER_TRANSFORM_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/return.h>
#include <mpllibs/metaparse/get_result.h>
#include <mpllibs/metaparse/get_remaining.h>
#include <mpllibs/metaparse/get_position.h>

#include <mpllibs/metaparse/util/unless_error.h>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p, class t>
    struct transform
    {
      template <class s, class pos>
      struct apply :
        mpllibs::metaparse::util::unless_error<
          boost::mpl::apply<p, s, pos>,
          boost::mpl::apply<
            mpllibs::metaparse::return_<
              boost::mpl::apply<
                t,
                mpllibs::metaparse::get_result<boost::mpl::apply<p, s, pos> >
              >
            >,
            mpllibs::metaparse::get_remaining<boost::mpl::apply<p, s, pos> >,
            mpllibs::metaparse::get_position<boost::mpl::apply<p, s, pos> >
          >
        >
      {};
    };
  }
}

#endif

