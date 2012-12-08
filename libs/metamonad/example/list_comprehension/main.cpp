// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/list.hpp>
#include <mpllibs/metamonad/do.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

#include <boost/mpl/fold.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/range_c.hpp>

#include <iostream>

using mpllibs::metamonad::tmp_value;

struct print_after : tmp_value<print_after>
{
  template <class Acc, class V>
  struct apply : tmp_value<apply<Acc, V> >
  {
    static bool run()
    {
      const bool first_element = Acc::type::run();
      std::cout
        << (first_element ? "" : ", ") << "("
        << boost::mpl::first<V>::type::value << ", "
        << boost::mpl::second<V>::type::value
        << ")";
      return false;
    }
  };
};

struct print_empty : tmp_value<print_empty>
{
  static bool run()
  {
    // The next element is the first one
    return true;
  }
};

template <class L>
void print_values()
{
  boost::mpl::fold<typename L::type, print_empty, print_after>::type::run();
}

struct i;
struct j;

int main()
{
  using mpllibs::metamonad::do_;
  using mpllibs::metamonad::list_tag;
  using mpllibs::metamonad::set;
  using mpllibs::metamonad::do_return;

  using boost::mpl::pair;
  using boost::mpl::list_c;
  using boost::mpl::range_c;

  /*
    List comprehension syntax in Haskell: [(i,j) | i <- [1,2], j <- [1..4]]

    Do syntax in Haskell:
      do i <- [1,2]
         j <- [1..4]
         return (i,j)

    Result in Haskell: [(1,1),(1,2),(1,3),(1,4),(2,1),(2,2),(2,3),(2,4)]
   */

  typedef list_c<int, 1, 2> i;
  typedef list_c<int, 1, 2, 3, 4> j;

  typedef
    do_<list_tag>::apply<
      set<i, list_c<int, 1, 2> >,
      set<j, range_c<int, 1, 5> >,
      do_return<pair<i, j> >
    >
    result_of_list_comprehension;
  
  print_values<result_of_list_comprehension>();
  std::cout << std::endl;
}

