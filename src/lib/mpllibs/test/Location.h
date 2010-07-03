#ifndef MPLLIBS_TEST_LOCATION_H
#define MPLLIBS_TEST_LOCATION_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include <iostream>

namespace mpllibs
{
  namespace test
  {
    class Location
    {
    public:
      Location(const std::string& filename_, int lineNumber_) :
        _filename(filename_),
        _lineNumber(lineNumber_)
      {}
      
      const std::string& filename() const
      {
        return _filename;
      }
      
      int lineNumber() const
      {
        return _lineNumber;
      }
    private:
      std::string _filename;
      int _lineNumber;
    };
    
    inline std::ostream& operator<<(std::ostream& out_, const Location& l_)
    {
      return out_ << l_.filename() << ":" << l_.lineNumber();
    }
  }
}

#endif

