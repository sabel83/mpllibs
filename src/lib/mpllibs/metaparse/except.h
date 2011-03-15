#ifndef MPLLIBS_PARSER_EXCEPT_H
#define MPLLIBS_PARSER_EXCEPT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/accept.h>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p, class result, class error_msg>
    struct except
    {
      template <class s, class pos>
      struct apply :
        boost::mpl::eval_if<
          typename mpllibs::metaparse::is_error<
            boost::mpl::apply<p, s, pos>
          >::type,
          mpllibs::metaparse::accept<boost::mpl::identity<result>, s, pos>,
          mpllibs::metaparse::error<error_msg, pos>
        >
      {};
    };
  }
}

#endif

