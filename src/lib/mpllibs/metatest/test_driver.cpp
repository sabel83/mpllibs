// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test_driver.h>

#include <boost/pool/detail/singleton.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/bind.hpp>

#include <algorithm>
#include <iostream>

using mpllibs::metatest::test_driver;

using std::ostream;

test_driver::~test_driver()
{
  using std::cout;
  
  // Print summary in the destructor to make sure it's executed after
  // the tests
  cout << *this;
}

ptrdiff_t test_driver::failure_count() const
{
  using std::count_if;
  using boost::bind;
  
  return
    count_if(
      _results.begin(),
      _results.end(),
      !bind(&test_result::success, _1)
    );
}

size_t test_driver::total_count() const
{
  return _results.size();
}
    
test_driver& test_driver::instance()
{
  return boost::details::pool::singleton_default<test_driver>::instance();
}

test_driver::const_iterator test_driver::begin() const
{
  return _results.begin();
}

test_driver::const_iterator test_driver::end() const
{
  return _results.end();
}

int test_driver::main(int, char*[]) const
{
  // Summary is printed in the destructor
  return this->failure_count() > 0 ? 1 : 0;
}

void test_driver::add(const test_result& result_)
{
  test_driver::instance()._results.push_back(result_);
}

ostream& mpllibs::metatest::operator<<(ostream& out_, const test_driver& d_)
{
  using std::for_each;
  using std::endl;
  using boost::lambda::_1;
  using boost::lambda::constant;

  out_ << "The following tests have been executed:" << endl;
    
  for_each(d_.begin(), d_.end(), out_ << constant("  ") << _1);
      
  out_ << "========================" << std::endl;
  out_ << "Number of tests: " << d_.total_count() << endl;
  out_ << "Number of failures: " << d_.failure_count() << endl;
      
  return out_;
}


