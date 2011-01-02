#ifndef MPLLIBS_TEST_TEST_RESULT_H
#define MPLLIBS_TEST_TEST_RESULT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/Location.h>
#include <mpllibs/metatest/TestSuite.h>

namespace mpllibs
{
  namespace metatest
  {
    class TestResult
    {
    public:
      TestResult(
        const mpllibs::metatest::TestSuite& suite_,
        const std::string& name_,
        const mpllibs::metatest::Location& location_,
        bool success_,
        const std::string& reason_
      );
      
      const std::string& name() const;
      const mpllibs::metatest::Location& location() const;
      
      bool success() const;
      
      const std::string& reason() const;
      
      bool hasReason() const;
      
      const mpllibs::metatest::TestSuite& testSuite() const;
    private:
      mpllibs::metatest::TestSuite _suite;
      std::string _name;
      mpllibs::metatest::Location _location;
      bool _success;
      std::string _reason;
    };
    
    std::ostream& operator<<(std::ostream& out_, const TestResult& r_);
  }
}

#endif

