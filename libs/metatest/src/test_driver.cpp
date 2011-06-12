// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test_driver.hpp>
#include <mpllibs/metatest/test_suite.hpp>

#include <boost/pool/detail/singleton.hpp>

using mpllibs::metatest::test_driver;
using mpllibs::metatest::test_suite;

test_driver& test_driver::instance()
{
  return boost::details::pool::singleton_default<test_driver>::instance();
}

void test_driver::add(const suite_path& suite_, const test_result& result_)
{
  test_driver::instance()._suite.add(
    suite_.begin(),
    suite_.end(),
    result_
  );
}

const test_suite& test_driver::suite() const
{
  return _suite;
}


