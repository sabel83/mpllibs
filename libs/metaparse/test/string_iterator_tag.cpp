// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/impl/string_iterator_tag.hpp>

#include <boost/type_traits/is_same.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_string_iterator_tag)
{
  using mpllibs::metaparse::v1::impl::string_iterator_tag;
  
  using boost::is_same;

  // test_metaprogramming_value
  BOOST_MPL_ASSERT((is_same<string_iterator_tag, string_iterator_tag::type>));
}


