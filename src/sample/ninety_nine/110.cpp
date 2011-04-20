#include <mpllibs/metatest/test.h>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/arithmetic.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/comparison.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/logical.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/reverse.hpp>
#include <boost/mpl/tag.hpp>
#include <boost/mpl/transform.hpp>

namespace mpl = boost::mpl;

namespace {
  const mpllibs::metatest::TestSuite suite ("99");
}


// Problem 1 
//
// (*) Find the last element of a list.

template <class List, class Tag, bool Empty>
struct myLast_impl
{
  typedef myLast_impl <List, Tag, Empty> type;
};

template <class List>
struct myLast_impl <List, mpl::tag <mpl::list <> > ::type, false>
  : mpl::if_ <
      typename mpl::empty <
        typename mpl::pop_front <List> ::type
      > ::type
    , typename mpl::front <List> ::type
    , typename myLast_impl <
        typename mpl::pop_front <List> ::type
      , typename mpl::tag <List> ::type
      , mpl::empty <
          typename mpl::pop_front <List> ::type
        > ::type::value
      > ::type
    >
{ };

template <class List>
struct myLast
  : myLast_impl <
      typename List::type
    , typename mpl::tag <typename List::type> ::type
    , mpl::empty <List> ::type::value
    >
{ };

namespace {
  typedef
    mpl::equal_to <
      myLast <mpl::list_c <int, 1, 2, 3> > ::type
    , mpl::int_ <3>
    >
  myLast_1;

  typedef
    mpl::equal_to <
      myLast <mpl::list_c <int, 1> > ::type
    , mpl::int_ <1>
    >
  myLast_2;

  typedef
    mpl::not_equal_to <
      myLast <mpl::list_c <int, 1, 2, 3> > ::type
    , mpl::int_ <2>
    >
  myLast_3;
}

MPLLIBS_ADD_TEST (suite, myLast_1)
MPLLIBS_ADD_TEST (suite, myLast_2)
MPLLIBS_ADD_TEST (suite, myLast_3)


// Problem 2 
// 
// Find the last but one element of a list.

template <class List>
struct myButLast
  : mpl::front <
      typename mpl::pop_front <
        typename mpl::reverse <
          typename List::type
        > ::type
      > ::type
    >
{ };

namespace {
  typedef
    mpl::equal_to <
      myButLast <mpl::list_c <int, 1, 2, 3> > ::type
    , mpl::int_ <2>
    >
  myButLast_1;

  typedef
    mpl::equal_to <
      myButLast <mpl::list_c <int, 1, 2> > ::type
    , mpl::int_ <1>
    >
  myButLast_2;
}

MPLLIBS_ADD_TEST (suite, myButLast_1)
MPLLIBS_ADD_TEST (suite, myButLast_2)


// Problem 3 
//
// (*) Find the K'th element of a list. The first element in the list is number 1.

template <class List, class ListTag, int N>
struct elementAt_impl
  : mpl::front <mpl::list0 <> >
{ };

template <class List>
struct elementAt_impl <List, mpl::tag <mpl::list <> > ::type, 1>
  : mpl::front <List>
{ };

template <class List, int N>
struct elementAt_impl <List, mpl::tag <mpl::list <> > ::type, N>
  : elementAt_impl <
      typename mpl::pop_front <List> ::type
    , typename mpl::tag <typename mpl::pop_front <List> ::type> ::type
    , N - 1
    >
{ };

template <class List, int N>
struct elementAt_c
  : elementAt_impl <
      typename List::type
    , typename mpl::tag <typename List::type> ::type
    , N
    >
{ };

template <class List, class N>
struct elementAt
  : elementAt_c <
      List
    , N::type::value
    >
{ };

namespace {
  typedef
    mpl::equal_to <
      elementAt_c <mpl::list_c <int, 1, 2, 3>, 2>
    , mpl::int_ <2>
    >
  elementAt_1;
}

MPLLIBS_ADD_TEST (suite, elementAt_1)

//template <class List, int n>
//struct elementAt_c
//{
//  template <class xs, int m>
//  struct elementAt_impl_c
//  {
//    typedef
//      typename elementAt_impl_c <
//        typename pop_front <xs> ::type
//      , m - 1
//      > ::type
//    type;
//  };
//
//  template <class xs>
//  struct elementAt_impl_c <xs, 1>
//  {
//    typedef
//      typename front <xs> ::type
//    type;
//  };
//
//  typedef typename elementAt_impl_c <List, n> ::type type;
//};


//Problem 4 
//
//(*) Find the number of elements of a list.

//template <class List>
//struct myLength
//{
//  template <class xs>
//  struct myLength_impl
//  {
//    typedef
//      typename plus <
//        int_<1>
//      , typename myLength_impl <
//          typename pop_front <xs> ::type
//        > ::type
//      > ::type
//    type;
//  };
//
//  template <class x>
//  struct myLength_impl <list1 <x> >
//  {
//    typedef int_<1> type;
//  };
//
//  typedef typename myLength_impl <List> ::type type;
//};
//
//template <>
//struct myLength <list0 <> >
//{
//  typedef int_<0> type;
//};


// Problem 5 
// 
// (*) Reverse a list.

//template <class List>
//struct myReverse
//{
//  template <class xs, class ys>
//  struct myReverse_impl
//  {
//    typedef
//      typename myReverse_impl <
//        typename pop_front <xs> ::type
//      , typename push_front <
//          ys
//        , typename front <xs> ::type
//        > ::type
//      > ::type
//    type;
//  };
//
//  template <class x, class ys>
//  struct myReverse_impl <list1 <x>, ys>
//  {
//    typedef
//      typename push_front <ys, x> ::type
//    type;
//  };
//
//  typedef typename myReverse_impl <List, list <> > ::type type;
//};
//
//template <>
//struct myReverse <list0 <> >
//{
//  typedef list <> type;
//};


// Problem 6 
// 
// (*) Find out whether a list is a palindrome. A palindrome can be read forward or backward; e.g. (x a m a x).

//template <class List>
//struct isPalindrome
//{
//  typedef
//    typename fold <
//      typename transform <
//        List
//      , typename reverse <List> ::type
//      , equal_to <_1, _2>
//      > ::type
//    , true_
//    , and_ <_1, _2>
//    > ::type
//  type;
//};


// Problem 7 
// 
// (**) Flatten a nested list structure. 
// 
// Transform a list, possibly holding lists as elements into a `flat' list by
// replacing each list with its elements (recursively).

template <class List>
struct flatten
{ };


// Problem 8 
// 
// (**) Eliminate consecutive duplicates of list elements. 
// 
// If a list contains repeated elements they should be replaced with a single copy
// of the element. The order of the elements should not be changed.

template <class List>
struct compress
{ };


// Problem 9 
// 
// (**) Pack consecutive duplicates of list elements into sublists. If a list
// contains repeated elements they should be placed in separate sublists.

template <class List>
struct pack
{ };


// Problem 10 
// 
// (*) Run-length encoding of a list. Use the result of problem P09 to
// implement the so-called run-length encoding data compression method.
// Consecutive duplicates of elements are encoded as lists (N E) where N is the
// number of duplicates of the element E.

template <class List>
struct encode
{ };


