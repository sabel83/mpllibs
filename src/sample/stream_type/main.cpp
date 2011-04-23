// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream.h>

#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/range_c.hpp>

#include <iostream>

class custom_test_class;
class other_custom_test_class;
class defined_custom_test_class {};

class custom_test_class_with_long_name;

DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(custom_test_class)
DEFINE_TO_STREAM_FOR_TYPE(custom_test_class_with_long_name, "short_name")

int main()
{
  using std::cout;
  using std::endl;
  using mpllibs::metatest::to_stream;
  
  to_stream<other_custom_test_class>::run(cout) << endl;
  to_stream<defined_custom_test_class>::run(cout) << endl;
  to_stream<custom_test_class_with_long_name>::run(cout) << endl;

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

  to_stream<vector_c<int, 1, 2, 3> >::run(cout) << endl;
  to_stream<list_c<int, 1, 2, 3> >::run(cout) << endl;
  to_stream<deque<int, float, char> >::run(cout) << endl;
  to_stream<range_c<int, 1, 10> >::run(cout) << endl;
  to_stream<vector_c<char, 'h', 'e', 'l', 'l', 'o'> >::run(cout) << endl;
  to_stream<vector<> >::run(cout) << endl;
  to_stream<_1>::run(cout) << endl;
  to_stream<apply<int, double> >::run(cout) << endl;
}

