#ifndef MPLLIBS_METATEST_LOCATION_HPP
#define MPLLIBS_METATEST_LOCATION_HPP

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
    class location
    {
    public:
      location(const std::string& filename_, int line_number_);
      
      const std::string& filename() const;
      
      int line_number() const;
    private:
      std::string _filename;
      int _line_number;
    };
    
    std::ostream& operator<<(std::ostream& out_, const location& l_);
  }
}

#endif

