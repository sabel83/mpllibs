// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/Location.h>

#include <iostream>

using namespace mpllibs::metatest;

Location::Location(const std::string& filename_, int lineNumber_) :
  _filename(filename_),
  _lineNumber(lineNumber_)
{}
      
const std::string& Location::filename() const
{
  return _filename;
}
      
int Location::lineNumber() const
{
  return _lineNumber;
}

std::ostream& mpllibs::metatest::operator<<(
  std::ostream& out_,
  const Location& l_
)
{
  return out_ << l_.filename() << ":" << l_.lineNumber();
}


