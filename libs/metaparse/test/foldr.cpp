// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/foldr.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <boost/mpl/list.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/lambda.hpp>

using mpllibs::metaparse::foldr;

using boost::mpl::list;
using boost::mpl::push_front;
using boost::mpl::_1;
using boost::mpl::_2;

namespace
{ 
  template <class P>
  struct any : foldr<P, list<>, push_front<_2, _1> >
  {
    struct to_stream
    {
      static std::ostream& run(std::ostream& o)
      {
        o << "foldr__any<";
        mpllibs::metatest::to_stream_argument_list<P>::run(o);
        return o << ">";
      }
    };
  };
}

#define DEFINE_TEST_CASE BOOST_AUTO_TEST_CASE(test_foldr)

#include "any_test.hpp"  

