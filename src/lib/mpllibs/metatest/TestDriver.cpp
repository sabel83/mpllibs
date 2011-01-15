// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/TestDriver.h>

#include <boost/pool/detail/singleton.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/bind.hpp>

#include <algorithm>
#include <iostream>

using namespace mpllibs::metatest;

TestDriver::~TestDriver()
{
  // Print summary in the destructor to make sure it's executed after
  // the tests
  std::cout << *this;
}

ptrdiff_t TestDriver::failureCount() const
{
  using std::count_if;
  using boost::bind;
  
  return
    count_if(_results.begin(), _results.end(), !bind(&TestResult::success, _1));
}

size_t TestDriver::totalCount() const
{
  return _results.size();
}
    
TestDriver& TestDriver::instance()
{
  return boost::details::pool::singleton_default<TestDriver>::instance();
}

TestDriver::const_iterator TestDriver::begin() const
{
  return _results.begin();
}

TestDriver::const_iterator TestDriver::end() const
{
  return _results.end();
}

int TestDriver::main(int, char*[]) const
{
  // Summary is printed in the destructor
  return this->failureCount() > 0 ? 1 : 0;
}

void TestDriver::add(const TestResult& result_)
{
  TestDriver::instance()._results.push_back(result_);
}

std::ostream& mpllibs::metatest::operator<<(
  std::ostream& out_,
  const TestDriver& d_
)
{
  using std::for_each;
  using std::endl;
  using boost::lambda::_1;
  using boost::lambda::constant;

  out_ << "The following tests have been executed:" << endl;
    
  for_each(d_.begin(), d_.end(), out_ << constant("  ") << _1);
      
  out_ << "========================" << std::endl;
  out_ << "Number of tests: " << d_.totalCount() << endl;
  out_ << "Number of failures: " << d_.failureCount() << endl;
      
  return out_;
}


