#ifndef MPLLIBS_METAPARSE_V2_EMPTY_HPP
#define MPLLIBS_METAPARSE_V2_EMPTY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/error/end_of_input_expected.hpp>
#include <mpllibs/metaparse/v2/reject.hpp>
#include <mpllibs/metaparse/v2/accept.hpp>
#include <mpllibs/metaparse/v2/define_error.hpp>

#include <boost/mpl/empty.hpp>
#include <boost/mpl/if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class Result>
      struct empty
      {
        typedef empty type;
        
        template <class S, class Pos>
        struct apply :
          boost::mpl::if_<
            boost::mpl::empty<S>,
            accept<Result, S, Pos>,
            reject<error::end_of_input_expected, Pos>
          >
        {};
      };
    }
  }
}

#endif

