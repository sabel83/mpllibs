#ifndef MPLLIBS_METAPARSE_TRANSFORM_HPP
#define MPLLIBS_METAPARSE_TRANSFORM_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>
#include <mpllibs/metaparse/get_position.hpp>

#include <mpllibs/metaparse/util/unless_error.hpp>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class T>
    struct transform
    {
      template <class S, class Pos>
      struct apply :
        mpllibs::metaparse::util::unless_error<
          boost::mpl::apply<P, S, Pos>,
          boost::mpl::apply<
            return_<
              boost::mpl::apply<T, get_result<boost::mpl::apply<P, S, Pos> > >
            >,
            get_remaining<boost::mpl::apply<P, S, Pos> >,
            get_position<boost::mpl::apply<P, S, Pos> >
          >
        >
      {};
    };
  }
}

#endif

