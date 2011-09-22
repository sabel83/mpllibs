#ifndef MPLLIBS_METATEST_LOCATION_HPP
#define MPLLIBS_METATEST_LOCATION_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include <iostream>

namespace mpllibs
{
  namespace metatest
  {
    #ifdef MPLLIBS_HERE
      #error MPLLIBS_HERE already defined
    #endif
    #define MPLLIBS_HERE (mpllibs::metatest::location(__FILE__, __LINE__))

    class location
    {
    public:
      location(const std::string& filename_, int line_number_) :
        _filename(filename_),
        _line_number(line_number_)
      {}
      
      const std::string& filename() const
      {
        return _filename;
      }
      
      int line_number() const
      {
        return _line_number;
      }
    private:
      std::string _filename;
      int _line_number;
    };
    
    inline std::ostream& operator<<(std::ostream& out_, const location& l_)
    {
      return out_ << l_.filename() << ":" << l_.line_number();
    }
  }
}

#endif

