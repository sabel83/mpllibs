// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/fail_with_type.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/box.hpp>
#include <mpllibs/metamonad/unbox.hpp>

using mpllibs::metamonad::box;
using mpllibs::metamonad::unbox;

MPLLIBS_METAFUNCTION(make_const, (T))
((
  box<const typename unbox<T>::type>
));

int main()
{
  using mpllibs::metamonad::fail_with_type;

  // Uncomment the following line to get the error report
  // fail_with_type< make_const<box<int> >::type >();
}


