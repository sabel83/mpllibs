// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "print_values.hpp"

#include <mpllibs/metamonad/list.hpp>
#include <mpllibs/metamonad/do_c.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/guard.hpp>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/equal_to.hpp>

#include <iostream>

int main()
{
  using mpllibs::metamonad::do_c;
  using mpllibs::metamonad::list_tag;
  using mpllibs::metamonad::set;
  using mpllibs::metamonad::do_return;
  using mpllibs::metamonad::guard;

  using boost::mpl::pair;
  using boost::mpl::list_c;
  using boost::mpl::range_c;
  using boost::mpl::equal_to;

  using namespace mpllibs::metamonad::name;

  /*
    List comprehension syntax in Haskell: [(i,j) | i <- [1,2], j <- [1..4]]

    Do syntax in Haskell:
      do i <- [1,2]
         j <- [1..4]
         return (i,j)

    Result in Haskell: [(1,1),(1,2),(1,3),(1,4),(2,1),(2,2),(2,3),(2,4)]
   */

  typedef
    do_c<list_tag,
      set<i, list_c<int, 1, 2> >,
      set<j, range_c<int, 1, 5> >,
      do_return<pair<i, j> >
    >
    result_of_list_comprehension;
  
  print_values<result_of_list_comprehension>();
  std::cout << std::endl;

  /*
    List comprehension syntax in Haskell:
      [(i,j) | i <- [1,2], j <- [1..4], i == j]

    Do syntax in Haskell:
      do i <- [1,2]
         j <- [1..4]
         Control.Monad.guard $ i == j
         return (i,j)

    Result in Haskell: [(1,1),(2,2)]
   */

  typedef
    do_c<list_tag,
      set<i, list_c<int, 1, 2> >,
      set<j, range_c<int, 1, 5> >,
      guard<list_tag, equal_to<i, j> >,
      do_return<pair<i, j> >
    >
    result_of_list_comprehension_with_guard;
  
  print_values<result_of_list_comprehension_with_guard>();
  std::cout << std::endl;
}

