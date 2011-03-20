#ifndef MPLLIBS_PARSER_EMPTY_H
#define MPLLIBS_PARSER_EMPTY_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/fail.h>
#include <mpllibs/metaparse/return.h>

#include <mpllibs/metaparse/util/define_data.h>

#include <mpllibs/metatest/to_stream.h>

#include <boost/mpl/empty.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/if.hpp>

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
        boost::mpl::apply<
          typename boost::mpl::if_<
            boost::mpl::empty<s>,
            mpllibs::metaparse::return_<result>,
            mpllibs::metaparse::fail<
              mpllibs::metaparse::errors::end_of_input_expected
            >
          >::type,
          s,
          pos
        >
      {};
    };
  }
}

DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metaparse::errors::end_of_input_expected,
  "End of input expected"
)

#endif

