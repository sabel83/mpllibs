#ifndef MPLLIBS_PARSER_EMPTY_H
#define MPLLIBS_PARSER_EMPTY_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/error.h>
#include <mpllibs/metaparse/accept.h>

#include <mpllibs/metaparse/util/define_data.h>

#include <boost/mpl/if.hpp>
#include <boost/mpl/empty.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace errors
    {
      MPLLIBS_METAPARSE_DEFINE_DATA(end_of_input_expected);
    }
  
    template <class result>
    struct empty
    {
      template <class s, class pos>
      struct apply :
        boost::mpl::if_<
          typename boost::mpl::empty<s>::type,
          mpllibs::metaparse::accept<result, s, pos>,
          mpllibs::metaparse::error<
            mpllibs::metaparse::errors::end_of_input_expected,
            pos
          >
        >
      {};
    };
  }
}

#endif

