#ifndef MPLLIBS_TEST_TEST_RESULT_H
#define MPLLIBS_TEST_TEST_RESULT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/location.h>

namespace mpllibs
{
  namespace metatest
  {
    class test_result
    {
    public:
      test_result(
        const std::string& name_,
        const location& location_,
        bool success_,
        const std::string& reason_
      );
      
      const std::string& get_name() const;
      const location& get_location() const;
      
      bool success() const;
      
      const std::string& get_reason() const;
      
      bool has_reason() const;
    private:
      std::string _name;
      location _location;
      bool _success;
      std::string _reason;
    };
  }
}

#endif

