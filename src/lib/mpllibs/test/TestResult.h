#ifndef MPLLIBS_TEST_TEST_RESULT_H
#define MPLLIBS_TEST_TEST_RESULT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/test/Location.h>

#include <cassert>

namespace mpllibs
{
  namespace test
  {
    class TestResult
    {
    public:
      TestResult(
        const std::string& name_,
        const Location& location_,
        bool success_,
        const std::string& reason_
      ) :
        _name(name_),
        _location(location_),
        _success(success_),
        _reason(reason_)
      {}
      
      const std::string& name() const
      {
        return _name;
      }
      const mpllibs::test::Location& location() const
      {
        return _location;
      }
      
      bool success() const
      {
        return _success;
      }
      
      const std::string& reason() const
      {
        assert(hasReason());
        
        return _reason;
      }
      
      bool hasReason() const
      {
        return _reason != "";
      }
    private:
      std::string _name;
      mpllibs::test::Location _location;
      bool _success;
      std::string _reason;
    };
    
    inline std::ostream& operator<<(std::ostream& out_, const TestResult& r_)
    {
      out_ << r_.name() << ": ";
      if (r_.success())
      {
        out_ << "OK";
      }
      else
      {
        out_ << "FAIL (" << r_.location() << ")";
        if (r_.hasReason())
        {
          out_ << std::endl << "\t" << r_.reason();
        }
      }
      return out_ << std::endl;
    }
  }
}

#endif

