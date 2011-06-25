#ifndef MPLLIBS_METAPARSE_EXCEPT_HPP
#define MPLLIBS_METAPARSE_EXCEPT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/fail.hpp>

#include <boost/mpl/if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class Result, class ErrorMsg>
    struct except
    {
      typedef except type;
      
      template <class S, class Pos>
      struct apply :
        boost::mpl::apply_wrap2<
          typename boost::mpl::if_<
            is_error<boost::mpl::apply<P, S, Pos> >,
            return_<Result>,
            fail<ErrorMsg>
          >::type,
          S,
          Pos
        >
      {};
    };
  }
}

#endif

