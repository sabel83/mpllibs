// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>
#include <mpllibs/metatest/boost_test.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <boost/mpl/times.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

using mpllibs::metatest::meta_require;

using boost::mpl::equal_to;
using boost::mpl::int_;

// Metafunction to test
template <class T>
struct double_ : boost::mpl::times<T, boost::mpl::int_<2> >
{
  struct to_stream
  {
    static std::ostream& run(std::ostream& o)
    {
      o << "double_";
      mpllibs::metatest::to_stream_argument_list<T>::run(o);
      return o << ">";
    }
  };
};

BOOST_AUTO_TEST_CASE(example)
{
  meta_require<
    equal_to<double_<int_<13> >::type, int_<26> >
  >(MPLLIBS_HERE, "test_success");
}


