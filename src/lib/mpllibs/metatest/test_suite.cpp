// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test_suite.h>

#include <iostream>

using mpllibs::metatest::test_suite;

using std::string;
using std::ostream;

test_suite::test_suite(const string& name_) :
  _name(name_)
{}
      
const string& test_suite::name() const
{
  return _name;
}

ostream& mpllibs::metatest::operator<<(ostream& out_, const test_suite& s_)
{
  return out_ << s_.name();
}


