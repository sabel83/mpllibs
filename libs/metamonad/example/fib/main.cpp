// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/eval_if.hpp>

#include <iostream>

using boost::mpl::plus;
using boost::mpl::minus;
using boost::mpl::less;
using boost::mpl::eval_if;
using boost::mpl::int_;

using mpllibs::metamonad::lazy;

// Without lazy
///////////////

template <class N>
struct fib_without_lazy;

MPLLIBS_METAFUNCTION(fib_without_lazy_helper, (N))
((
  plus<
    typename fib_without_lazy<typename minus<N, int_<1> >::type>::type,
    typename fib_without_lazy<typename minus<N, int_<2> >::type>::type
  >
));


MPLLIBS_METAFUNCTION(fib_without_lazy, (N))
((
  eval_if<
    typename less<N, int_<2> >::type,
    int_<1>,
    fib_without_lazy_helper<N>
  >
));

// With lazy
////////////

MPLLIBS_METAFUNCTION(fib, (N))
((
  eval_if<
    typename less<N, int_<2> >::type,
    int_<1>,
    lazy<plus<fib<minus<N, int_<1> > >, fib<minus<N, int_<2> > > > >
  >
));

///////////

int main()
{
  using std::endl;

  std::cout
    << "With lazy: " << endl
    << "fib(0) == " << fib_without_lazy<int_<0> >::type::value << endl
    << "fib(1) == " << fib_without_lazy<int_<1> >::type::value << endl
    << "fib(2) == " << fib_without_lazy<int_<2> >::type::value << endl
    << "fib(3) == " << fib_without_lazy<int_<3> >::type::value << endl
    << "fib(4) == " << fib_without_lazy<int_<4> >::type::value << endl
    << "fib(5) == " << fib_without_lazy<int_<5> >::type::value << endl
    << endl
    << "With lazy: " << endl
    << "fib(0) == " << fib<int_<0> >::type::value << endl
    << "fib(1) == " << fib<int_<1> >::type::value << endl
    << "fib(2) == " << fib<int_<2> >::type::value << endl
    << "fib(3) == " << fib<int_<3> >::type::value << endl
    << "fib(4) == " << fib<int_<4> >::type::value << endl
    << "fib(5) == " << fib<int_<5> >::type::value << endl;
}

