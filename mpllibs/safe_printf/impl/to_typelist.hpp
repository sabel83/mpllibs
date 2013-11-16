#ifndef MPLLIBS_SAFE_PRINTF_IMPL_TO_TYPELIST_HPP
#define MPLLIBS_SAFE_PRINTF_IMPL_TO_TYPELIST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/impl/expected_arg.hpp>

#include <mpllibs/metamonad/data.hpp>
#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/name.hpp>

#include <boost/mpl/vector.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    namespace impl
    {
      using namespace metamonad::name;

      MPLLIBS_METAFUNCTION(to_typelist, (E))
      ((
        metamonad::eval_case< E,
          metamonad::matches_c<
            expected_arg<boost::mpl::true_, boost::mpl::true_, t>,
            boost::mpl::vector<metamonad::box<int>, metamonad::box<int>, t>
          >,
          metamonad::matches_c<
            expected_arg<boost::mpl::true_, boost::mpl::false_, t>,
            boost::mpl::vector<metamonad::box<int>, t>
          >,
          metamonad::matches_c<
            expected_arg<boost::mpl::false_, boost::mpl::true_, t>,
            boost::mpl::vector<metamonad::box<int>, t>
          >,
          metamonad::matches_c<
            expected_arg<boost::mpl::false_, boost::mpl::false_, t>,
            boost::mpl::vector<t>
          >
        >
      ));
    }
  }
}

#endif

