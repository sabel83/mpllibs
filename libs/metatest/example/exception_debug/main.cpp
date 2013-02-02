// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/try_c.hpp>
#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

#include <mpllibs/metatest/debug.hpp>
#include <mpllibs/metatest/to_stream.hpp>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/divides.hpp>

using boost::mpl::int_;
using boost::mpl::eval_if;
using boost::mpl::equal_to;
using boost::mpl::divides;

using mpllibs::metatest::debug;

using mpllibs::metamonad::try_c;
using mpllibs::metamonad::exception;
using mpllibs::metamonad::tmp_value;

typedef int_<0> int0;
typedef int_<13> int13;

struct division_by_zero : tmp_value<division_by_zero> {};
MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(division_by_zero, "division by zero")

template <class A, class B>
struct safe_divides :
  try_c<
    eval_if<
      typename equal_to<B, int0>::type,
      exception<division_by_zero>,
      divides<A, B>
    >
  >
{};

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, safe_divides, "safe_divides")

debug<safe_divides<int13, int0> > d;

int main()
{
  // some other code
}


