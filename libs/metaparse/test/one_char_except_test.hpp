// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// This header file contains code that is reused by other cpp files

#include <mpllibs/metaparse/source_position.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/preprocessor/cat.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(BOOST_PP_CAT(TEST_NAME, _except))
{
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::start;

  using boost::mpl::apply_wrap2;
  
  // rejects_except_char
  BOOST_MPL_ASSERT((is_error<apply_wrap2<oc, str_0, start> >));

  // rejects_other_except_char
  BOOST_MPL_ASSERT((is_error<apply_wrap2<oc, str_1, start> >));
}

#include "one_char_test.hpp"


