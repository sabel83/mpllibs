#ifndef MPLLIBS_METAPARSE_EMPTY_HPP
#define MPLLIBS_METAPARSE_EMPTY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/fail.hpp>
#include <mpllibs/metaparse/return.hpp>

#include <mpllibs/metaparse/util/define_data.hpp>

#include <mpllibs/metatest/to_stream.hpp>

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
    
    template <class Result>
    struct empty
    {
      typedef empty type;
      
      template <class S, class Pos>
      struct apply :
        boost::mpl::apply<
          typename boost::mpl::if_<
            boost::mpl::empty<S>,
            return_<Result>,
            fail<mpllibs::metaparse::errors::end_of_input_expected>
          >::type,
          S,
          Pos
        >
      {};
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metaparse::errors::end_of_input_expected,
  "End of input expected"
)

#endif

