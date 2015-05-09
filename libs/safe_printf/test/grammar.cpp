// Copyright Abel Sinkovics (abel@sinkovics.hu) 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/v1/impl/grammar.hpp>

#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/start.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/assert.hpp> 

BOOST_AUTO_TEST_CASE(test_invalid_format_string)
{
  using mpllibs::safe_printf::v1::impl::grammar::S;

  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::string;
  using mpllibs::metaparse::start;

  BOOST_MPL_ASSERT(( is_error<S::apply<string<'%'>, start> > ));
}

