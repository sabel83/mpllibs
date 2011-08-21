// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "min.hpp"

#include <mpllibs/metamonad/tag_tag.hpp>
#include <mpllibs/metamonad/meta_atom.hpp>

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::exception;

using boost::mpl::int_;
using boost::mpl::equal_to;

namespace
{
  const suite_path suite("min");
  
  MPLLIBS_DEFINE_TAG(test_class_tag)
  MPLLIBS_DEFINE_META_ATOM(test_class_tag, test_class)
  
  typedef equal_to<int_<11>, min<int_<11>, int_<13> >::type> test_integers;

  typedef
    equal_to<exception<non_comparable>, min<test_class, test_class>::type>
    test_non_comparable;
}

MPLLIBS_ADD_TEST(suite, test_integers)
MPLLIBS_ADD_TEST(suite, test_non_comparable)



