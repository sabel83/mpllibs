#ifndef MPLLIBS_TEST_LOCATION_H
#define MPLLIBS_TEST_LOCATION_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include <iosfwd>

namespace mpllibs
{
  namespace metatest
  {
    class Location
    {
    public:
      Location(const std::string& filename_, int lineNumber_);
      
      const std::string& filename() const;
      
      int lineNumber() const;
    private:
      std::string _filename;
      int _lineNumber;
    };
    
    std::ostream& operator<<(std::ostream& out_, const Location& l_);
  }
}

#endif

