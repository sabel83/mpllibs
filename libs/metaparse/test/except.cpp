// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/except.hpp>
#include <mpllibs/metaparse/one_char.hpp>
#include <mpllibs/metaparse/fail.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <mpllibs/metamonad/meta_atom.hpp>

#include "common.hpp"

#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

namespace
{
  using mpllibs::metaparse::error_tag;

  MPLLIBS_DEFINE_META_ATOM(error_tag, test_error)
}

BOOST_AUTO_TEST_CASE(test_except)
{
  using mpllibs::metatest::has_type;
  using mpllibs::metatest::meta_require;
  
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::except;
  using mpllibs::metaparse::one_char;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::fail;
  
  using boost::mpl::apply_wrap2;
  using boost::mpl::equal_to;

  meta_require<
    has_type<except<one_char, int13, test_error> >
  >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    is_error<
      apply_wrap2<except<one_char, int13, test_error>, str_hello, start>
    >
  >(MPLLIBS_HERE, "test_with_good");
  
  meta_require<
    equal_to<
      get_result<
        apply_wrap2<
          except<fail<test_error>, int13, test_error>,
          str_hello,
          start
        >
      >::type,
      int13
    >
  >(MPLLIBS_HERE, "test_with_bad");
}



