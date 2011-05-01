// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test_result.h>

#include <iostream>
#include <cassert>

using mpllibs::metatest::test_result;
using mpllibs::metatest::test_suite;
using mpllibs::metatest::location;

using std::string;
using std::ostream;

test_result::test_result(
  const test_suite& suite_,
  const string& name_,
  const location& location_,
  bool success_,
  const string& reason_
) :
  _suite(suite_),
  _name(name_),
  _location(location_),
  _success(success_),
  _reason(reason_)
{}
      
const string& test_result::get_name() const
{
  return _name;
}

const location& test_result::get_location() const
{
  return _location;
}
      
bool test_result::success() const
{
  return _success;
}
      
const string& test_result::get_reason() const
{
  assert(has_reason());
        
  return _reason;
}
      
bool test_result::has_reason() const
{
  return _reason != "";
}
      
const test_suite& test_result::get_suite() const
{
  return _suite;
}

ostream& mpllibs::metatest::operator<<(ostream& out_, const test_result& r_)
{
  using std::endl;

  out_ << r_.get_suite() << "::" << r_.get_name() << ": ";
  if (r_.success())
  {
    out_ << "OK";
  }
  else
  {
    out_ << "FAIL (" << r_.get_location() << ")";
    if (r_.has_reason())
    {
      out_ << endl << "\t" << r_.get_reason();
    }
  }
  return out_ << endl;
}

