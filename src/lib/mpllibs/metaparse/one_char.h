#ifndef MPLLIBS_PARSER_ONE_CHAR_H
#define MPLLIBS_PARSER_ONE_CHAR_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/next_char.h>
#include <mpllibs/metaparse/return.h>
#include <mpllibs/metaparse/fail.h>

#include <mpllibs/metaparse/util/define_data.h>

#include <mpllibs/metatest/to_stream.h>

#include <boost/mpl/empty.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace errors
    {
      MPLLIBS_METAPARSE_DEFINE_DATA(unexpected_end_of_input);
    }
    
    struct one_char
    {
      template <class s, class pos>
      struct apply :
        boost::mpl::eval_if<
          typename boost::mpl::empty<s>::type,
          boost::mpl::apply<
            mpllibs::metaparse::fail<
              mpllibs::metaparse::errors::unexpected_end_of_input
            >,
            s,
            pos
          >,
          boost::mpl::apply<
            mpllibs::metaparse::return_<boost::mpl::front<s> >,
            boost::mpl::pop_front<s>,
            mpllibs::metaparse::next_char<pos>
          >
        >
      {};
    };
  }
}

DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metaparse::errors::unexpected_end_of_input,
  "Unexpected end of input"
)

#endif

