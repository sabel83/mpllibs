#ifndef MPLLIBS_TEST_TEST_SUITE_H
#define MPLLIBS_TEST_TEST_SUITE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include <iostream>

namespace mpllibs
{
  namespace metatest
  {
    class TestSuite
    {
    public:
      explicit TestSuite(const std::string& name_) :
        _name(name_)
      {}
      
      const std::string& name() const
      {
        return _name;
      }
    private:
      std::string _name;
    };
    
    inline std::ostream& operator<<(std::ostream& out_, const TestSuite& s_)
    {
      return out_ << s_.name();
    }
  }
}

#endif

