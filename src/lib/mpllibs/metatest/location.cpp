// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/location.h>

#include <iostream>

using mpllibs::metatest::location;

using std::string;
using std::ostream;

location::location(const string& filename_, int line_number_) :
  _filename(filename_),
  _line_number(line_number_)
{}
      
const string& location::filename() const
{
  return _filename;
}
      
int location::line_number() const
{
  return _line_number;
}

ostream& mpllibs::metatest::operator<<(ostream& out_, const location& l_)
{
  return out_ << l_.filename() << ":" << l_.line_number();
}


