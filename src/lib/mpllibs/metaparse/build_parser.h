#ifndef MPLLIBS_PARSER_BUILD_PARSER_H
#define MPLLIBS_PARSER_BUILD_PARSER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p>
    struct build_parser
    {
      template <class s>
      struct apply :
        mpllibs::metaparse::get_result<
          boost::mpl::apply<p, s, mpllibs::metaparse::start>
        >
      {};
    };
  }
}

#endif

