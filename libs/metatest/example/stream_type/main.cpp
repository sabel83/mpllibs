// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream.hpp>

#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/set.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/insert.hpp>

#include <iostream>

using boost::mpl::int_;

class custom_test_class;
class other_custom_test_class;
class defined_custom_test_class {};

class custom_test_class_with_long_name;

struct metafunction_class
{
  typedef metafunction_class type;
  
  template <class T>
  struct apply : int_<13> {};
};

MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(custom_test_class)
MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  custom_test_class_with_long_name,
  "short_name"
)
MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(metafunction_class)

template <class T>
struct cant_be_instantiated : T::doesnt_exist {};

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  cant_be_instantiated,
  "can't be instantiated"
)

int main()
{
  using std::cout;
  using std::endl;
  using mpllibs::metatest::to_stream;
  using boost::mpl::integral_c;
  using boost::mpl::true_;
  using boost::mpl::false_;
  using boost::mpl::int_;
  using boost::mpl::long_;
  using boost::mpl::char_;
  using boost::mpl::void_;
  using boost::mpl::string;
  using boost::mpl::vector_c;
  using boost::mpl::list_c;
  using boost::mpl::deque;
  using boost::mpl::range_c;
  using boost::mpl::vector;
  using boost::mpl::_1;
  using boost::mpl::apply;
  using boost::mpl::lambda;
  using boost::mpl::list;
  using boost::mpl::set;
  using boost::mpl::map;
  using boost::mpl::pair;
  using boost::mpl::push_front;
  using boost::mpl::insert;
   
  to_stream<other_custom_test_class>::run(cout) << endl;
  to_stream<defined_custom_test_class>::run(cout) << endl;
  to_stream<custom_test_class_with_long_name>::run(cout) << endl;
  to_stream<cant_be_instantiated<int> >::run(cout) << endl;

  to_stream<int>::run(cout) << endl;
  to_stream<double>::run(cout) << endl;
  to_stream<custom_test_class>::run(cout) << endl;
  to_stream<const char*>::run(cout) << endl;
  to_stream<char * const>::run(cout) << endl;
  to_stream<double**>::run(cout) << endl;
  to_stream<float* const *>::run(cout) << endl;
  to_stream<long * const * const>::run(cout) << endl;
  to_stream<short&>::run(cout) << endl;
  to_stream<signed char[]>::run(cout) << endl;
  to_stream<const char*[]>::run(cout) << endl;
  to_stream<void>::run(cout) << endl;
  to_stream<size_t>::run(cout) << endl;
  cout << endl;
 
  to_stream<integral_c<int, 13> >::run(cout) << endl;
  to_stream<true_>::run(cout) << endl;
  to_stream<int_<19> >::run(cout) << endl;
  to_stream<long_<83> >::run(cout) << endl;
  to_stream<char_<'\n'> >::run(cout) << endl;
  to_stream<char_<'X'> >::run(cout) << endl;
  to_stream<char_<'\x03'> >::run(cout) << endl;
  to_stream<boost::mpl::size_t<13> >::run(cout) << endl;
  to_stream<void_>::run(cout) << endl;
  to_stream<string<'s'> >::run(cout) << endl;
  to_stream<string<'\n'> >::run(cout) << endl;

  to_stream<
    map<pair<int_<1>, int_<2> >, pair<int_<3>, int_<4> > >::type
  >::run(cout) << endl;
  to_stream<map<>::type>::run(cout) << endl;
  to_stream<insert<map<>, pair<int_<1>, int_<2> > >::type>::run(cout) << endl;
  to_stream<set<int_<1>, int_<2>, int_<3> >::type>::run(cout) << endl;
  to_stream<set<>::type>::run(cout) << endl;
  to_stream<insert<set<>, int_<13> >::type>::run(cout) << endl;
  to_stream<deque<int_<1>, int_<2>, int_<3> >::type>::run(cout) << endl;
  to_stream<deque<>::type>::run(cout) << endl;
  to_stream<list<int_<1>, int_<2>, int_<3> >::type>::run(cout) << endl;
  to_stream<
    push_front<list<int_<1>, int_<2>, int_<3> >, int>::type
  >::run(cout) << endl;
  to_stream<list<>::type>::run(cout) << endl;
  to_stream<push_front<list<>, int>::type>::run(cout) << endl;
  to_stream<vector<int_<1>, int_<2>, int_<3> >::type>::run(cout) << endl;
  to_stream<
    push_front<vector<int_<1>, int_<2>, int_<3> >, int>::type
  >::run(cout) << endl;
  to_stream<vector<>::type>::run(cout) << endl;
  to_stream<push_front<vector<>, int>::type>::run(cout) << endl;
  to_stream<vector_c<int, 1, 2, 3> >::run(cout) << endl;
  to_stream<vector<int_<1>, int_<2>, int_<3> > >::run(cout) << endl;
  to_stream<list_c<int, 1, 2, 3> >::run(cout) << endl;
  to_stream<deque<int, float, char> >::run(cout) << endl;
  to_stream<range_c<int, 1, 10> >::run(cout) << endl;
  to_stream<vector_c<char, 'h', 'e', 'l', 'l', 'o'> >::run(cout) << endl;
  to_stream<vector<> >::run(cout) << endl;
  to_stream<_1>::run(cout) << endl;
  to_stream<lambda<_1> >::run(cout) << endl;
  to_stream<apply<metafunction_class, double> >::run(cout) << endl;
}

