// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/try_c.hpp>
#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/data.hpp>
#include <mpllibs/metamonad/value_to_stream.hpp>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/divides.hpp>

#include <iostream>

using boost::mpl::int_;
using boost::mpl::eval_if;
using boost::mpl::equal_to;
using boost::mpl::divides;

using mpllibs::metamonad::try_c;
using mpllibs::metamonad::exception;

typedef int_<0> int0;
typedef int_<13> int13;

MPLLIBS_DATA(division_by_zero, 0, ((division_by_zero, 0)));

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

int main()
{
  mpllibs::metamonad::value_to_stream<
    safe_divides<int13, int0>
  >::run(std::cout);
  std::cout << std::endl;
}


