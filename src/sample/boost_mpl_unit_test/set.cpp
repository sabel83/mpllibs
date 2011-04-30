// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/set.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/erase.hpp>
#include <boost/mpl/erase_key.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/clear.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/mpl/order.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/type_traits/is_same.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite ("set");

  using namespace boost::mpl;
  using boost::is_same;

  namespace empty_set_test
  {
  }
}

//template< typename s >
//void empty_set_test()
//{
//    MPL_ASSERT_RELATION( size<s>::value, ==, 0 );
//    MPL_ASSERT(( empty<s> ));
//    
//    MPL_ASSERT(( is_same< BOOST_DEDUCED_TYPENAME clear<s>::type, set0<> > ));
//    MPL_ASSERT(( is_same< BOOST_DEDUCED_TYPENAME at<s,int>::type, void_ > ));
//    MPL_ASSERT(( is_same< BOOST_DEDUCED_TYPENAME at<s,char>::type, void_ > ));
//    MPL_ASSERT(( is_same< BOOST_DEDUCED_TYPENAME at<s,long>::type, void_ > ));
//
//    MPL_ASSERT_NOT(( has_key<s,int> ));
//    MPL_ASSERT_NOT(( has_key<s,char> ));
//    MPL_ASSERT_NOT(( has_key<s,long> ));
//
//    typedef BOOST_DEDUCED_TYPENAME order<s,int>::type o1;
//    typedef BOOST_DEDUCED_TYPENAME order<s,char>::type o2;
//    typedef BOOST_DEDUCED_TYPENAME order<s,long>::type o3;
//    MPL_ASSERT(( is_same< o1, void_ > ));
//    MPL_ASSERT(( is_same< o2, void_ > ));
//    MPL_ASSERT(( is_same< o3, void_ > ));
//    
//    typedef BOOST_DEDUCED_TYPENAME begin<s>::type first;
//    typedef BOOST_DEDUCED_TYPENAME end<s>::type last;
//
//    MPL_ASSERT(( is_same<first, last> ));
//    MPL_ASSERT_RELATION( (distance<first, last>::value), ==, 0 );
//}
