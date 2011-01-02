// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/TestResult.h>

#include <iostream>
#include <cassert>

using namespace mpllibs::metatest;

TestResult::TestResult(
  const mpllibs::metatest::TestSuite& suite_,
  const std::string& name_,
  const mpllibs::metatest::Location& location_,
  bool success_,
  const std::string& reason_
) :
  _suite(suite_),
  _name(name_),
  _location(location_),
  _success(success_),
  _reason(reason_)
{}
      
const std::string& TestResult::name() const
{
  return _name;
}

const Location& TestResult::location() const
{
  return _location;
}
      
bool TestResult::success() const
{
  return _success;
}
      
const std::string& TestResult::reason() const
{
  assert(hasReason());
        
  return _reason;
}
      
bool TestResult::hasReason() const
{
  return _reason != "";
}
      
const TestSuite& TestResult::testSuite() const
{
  return _suite;
}

std::ostream& mpllibs::metatest::operator<<(
  std::ostream& out_,
  const TestResult& r_
)
{
  using std::endl;

  out_ << r_.testSuite() << "::" << r_.name() << ": ";
  if (r_.success())
  {
    out_ << "OK";
  }
  else
  {
    out_ << "FAIL (" << r_.location() << ")";
    if (r_.hasReason())
    {
      out_ << endl << "\t" << r_.reason();
    }
  }
  return out_ << endl;
}

