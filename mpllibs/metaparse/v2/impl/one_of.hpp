#ifndef MPLLIBS_METAPARSE_V2_IMPL_ONE_OF_HPP
#define MPLLIBS_METAPARSE_V2_IMPL_ONE_OF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/error/none_of_the_expected_cases_found.hpp>
#include <mpllibs/metaparse/v2/fail.hpp>

#include <mpllibs/metaparse/v2/impl/one_of_fwd_op.hpp>

#include <boost/mpl/fold.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace impl
      {
        template <class Parsers>
        struct one_of
        {
          typedef one_of type;

          template <class S, class Pos>
          struct apply :
            boost::mpl::fold<
              Parsers,
              fail<error::none_of_the_expected_cases_found>::apply<S, Pos>,
              one_of_fwd_op<S, Pos>
            >::type
          {};
        };
      }
    }
  }
}

#endif

