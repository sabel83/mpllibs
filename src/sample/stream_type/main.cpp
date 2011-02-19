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

class CustomTestClass;
class OtherCustomTestClass;
class DefinedCustomTestClass {};

class CustomTestClassWithLongName;

DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(CustomTestClass)
DEFINE_TO_STREAM_FOR_TYPE(CustomTestClassWithLongName, "short_name")

int main()
{
  using std::cout;
  using std::endl;
  
  mpllibs::metatest::to_stream<OtherCustomTestClass>::run(cout) << endl;
  mpllibs::metatest::to_stream<DefinedCustomTestClass>::run(cout) << endl;
  mpllibs::metatest::to_stream<CustomTestClassWithLongName>::run(cout) << endl;

  mpllibs::metatest::to_stream<int>::run(cout) << endl;
  mpllibs::metatest::to_stream<double>::run(cout) << endl;
  mpllibs::metatest::to_stream<CustomTestClass>::run(cout) << endl;
  mpllibs::metatest::to_stream<const char*>::run(cout) << endl;
  mpllibs::metatest::to_stream<char * const>::run(cout) << endl;
  mpllibs::metatest::to_stream<double**>::run(cout) << endl;
  mpllibs::metatest::to_stream<float* const *>::run(cout) << endl;
  mpllibs::metatest::to_stream<long * const * const>::run(cout) << endl;
  mpllibs::metatest::to_stream<short&>::run(cout) << endl;
  mpllibs::metatest::to_stream<signed char[]>::run(cout) << endl;
  mpllibs::metatest::to_stream<const char*[]>::run(cout) << endl;
  mpllibs::metatest::to_stream<void>::run(cout) << endl;
  mpllibs::metatest::to_stream<size_t>::run(cout) << endl;
  cout << endl;
  
  using boost::mpl::integral_c;
  using boost::mpl::true_;
  using boost::mpl::false_;
  using boost::mpl::int_;
  using boost::mpl::long_;
  using boost::mpl::char_;
  using boost::mpl::void_;
  
  mpllibs::metatest::to_stream<integral_c<int, 13> >::run(cout) << endl;
  mpllibs::metatest::to_stream<true_>::run(cout) << endl;
  mpllibs::metatest::to_stream<int_<19> >::run(cout) << endl;
  mpllibs::metatest::to_stream<long_<83> >::run(cout) << endl;
  mpllibs::metatest::to_stream<char_<'\n'> >::run(cout) << endl;
  mpllibs::metatest::to_stream<char_<'X'> >::run(cout) << endl;
  mpllibs::metatest::to_stream<char_<'\x03'> >::run(cout) << endl;
  mpllibs::metatest::to_stream<boost::mpl::size_t<13> >::run(cout) << endl;
  mpllibs::metatest::to_stream<void_>::run(cout) << endl;
  mpllibs::metatest::to_stream<boost::mpl::string<'s'> >::run(cout) << endl;
  mpllibs::metatest::to_stream<boost::mpl::string<'\n'> >::run(cout) << endl;

  mpllibs::metatest::to_stream<boost::mpl::vector_c<int, 1, 2, 3> >::run(cout)
    << endl;
  mpllibs::metatest::to_stream<boost::mpl::list_c<int, 1, 2, 3> >::run(cout)
    << endl;
  mpllibs::metatest::to_stream<boost::mpl::deque<int, float, char> >::run(cout)
    << endl;
  mpllibs::metatest::to_stream<boost::mpl::range_c<int, 1, 10> >::run(cout)
    << endl;
  mpllibs::metatest::to_stream<
    boost::mpl::vector_c<char, 'h', 'e', 'l', 'l', 'o'>
  >::run(cout) << endl;
  mpllibs::metatest::to_stream<boost::mpl::vector<> >::run(cout) << endl;
}

