// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// This header file contains code that is reused by other cpp files

#include <mpllibs/metatest/boost_test.hpp>
#include <mpllibs/metaparse/source_position.hpp>

#include <boost/mpl/apply_wrap.hpp>

#include <boost/preprocessor/cat.hpp>

BOOST_AUTO_TEST_CASE(BOOST_PP_CAT(TEST_NAME, _except))
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::start;

  using boost::mpl::apply_wrap2;
  
  meta_require<
    is_error<apply_wrap2<oc, str_0, start> >
  >(MPLLIBS_HERE, "rejects_except_char");

  meta_require<
    is_error<apply_wrap2<oc, str_1, start> >
  >(MPLLIBS_HERE, "rejects_other_except_char");
}

#include "one_char_test.hpp"


