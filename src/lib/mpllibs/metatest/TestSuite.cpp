// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/TestSuite.h>

#include <iostream>

using namespace mpllibs::metatest;

TestSuite::TestSuite(const std::string& name_) :
  _name(name_)
{}
      
const std::string& TestSuite::name() const
{
  return _name;
}

std::ostream& mpllibs::metatest::operator<<(
  std::ostream& out_,
  const TestSuite& s_
)
{
  return out_ << s_.name();
}


