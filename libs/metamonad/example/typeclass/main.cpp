// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "print_values.hpp"

#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/lazy_protect_args.hpp>
#include <mpllibs/metamonad/if.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/apply.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/insert_range.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/equal_to.hpp>

#include <iostream>

using boost::mpl::int_;
using boost::mpl::plus;
using boost::mpl::minus;
using boost::mpl::list_c;
using boost::mpl::insert_range;
using boost::mpl::end;
using boost::mpl::equal_to;

using mpllibs::metamonad::lambda_c;
using mpllibs::metamonad::lazy;
using mpllibs::metamonad::lazy_protect_args;
using mpllibs::metamonad::if_;
using mpllibs::metamonad::tmp_value;
using mpllibs::metamonad::apply;

using namespace mpllibs::metamonad::name;

/*
 * The typeclass
 */
template <class Tag>
struct addable;
// Requires:
//   struct add { template <class, class> struct apply; };

MPLLIBS_METAFUNCTION(add, (Tag)(A)(B))
((apply<typename addable<Tag>::add, A, B>));

MPLLIBS_METAFUNCTION(double_, (Tag)(X))
((apply<typename addable<Tag>::double_, X>));

template <class Tag>
struct addable_defaults
{
  typedef lambda_c<n, add<Tag, n, n> > double_;
};

/*
 * Integers
 */
typedef int_<0>::tag int_tag;

template <>
struct addable<int_tag> : addable_defaults<int_tag>
{
  struct add : tmp_value<add>
  {
    MPLLIBS_LAZY_METAFUNCTION(apply, (A)(B)) ((int_<A::value + B::value>));
  };
};

/*
 * Lists
 */
typedef list_c<int>::tag list_tag;

template <>
struct addable<list_tag> : addable_defaults<list_tag>
{
  typedef
    lambda_c<a, b,
      lazy<
        insert_range<
          lazy_protect_args<a>,
          end<lazy_protect_args<a> >,
          lazy_protect_args<b>
        >
      >
    >
    add;
};

/*
 * Generic function
 */
MPLLIBS_LAZY_METAFUNCTION(mult, (T)(N))
((
  if_<
    equal_to<int_<1>, N>,
    T,
    add<typename T::tag, mult<T, minus<N, int_<1> > >, T>
  >
));


int main()
{
  using std::cout;
  using std::endl;

  cout
    << "add<int_tag, 11, 2> = " << add<int_tag, int_<11>, int_<2> >::type::value
    << endl;

  cout
    << "double_<int_tag, 3> = " << double_<int_tag, int_<3> >::type::value
    << endl;
    
  cout
    << "mult<3, 4> = " << mult<int_<3>, int_<4> >::type::value
    << endl;

  cout << "add<list_tag, [1, 2], [3, 4]> = ";
  print_values<add<list_tag, list_c<int, 1, 2>, list_c<int, 3, 4> > >();
  cout << endl;

  cout << "double_<list_tag, [1, 2]> = ";
  print_values<double_<list_tag, list_c<int, 1, 2> > >();
  cout << endl;

  cout << "mult<[1, 2], 4> = ";
  print_values<mult<list_c<int, 1, 2>, int_<4> > >();
  cout << endl;
}


