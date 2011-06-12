// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test_result.hpp>

#include <cassert>

using mpllibs::metatest::test_result;
using mpllibs::metatest::location;

using std::string;

test_result::test_result(
  const string& name_,
  const location& location_,
  bool success_,
  const string& reason_
) :
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

