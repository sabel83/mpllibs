#ifndef MPLLIBS_METATEST_TEST_RESULT_HPP
#define MPLLIBS_METATEST_TEST_RESULT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/location.hpp>
#include <mpllibs/metatest/has_type_value.hpp>
#include <mpllibs/metatest/get_type_value.hpp>
#include <mpllibs/metatest/has_type.hpp>
#include <mpllibs/metatest/to_stream.hpp>

#include <iostream>
#include <sstream>

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
      
      template <class Pred>
      static test_result build(
        const std::string& name_,
        const location& location_
      )
      {
        using std::ostringstream;
        using std::string;
        using boost::mpl::false_;
        
        const bool has_t = has_type<Pred>::type::value;
        const bool has_v = has_type_value<Pred, bool>::type::value;
        const bool result = get_type_value<Pred, false_>::type::value;
        
        ostringstream s;
        to_stream<Pred>::run(s);

        const bool success = has_t && has_v && result;

        const string reason =
          has_t ?
            (
              has_v ?
                s.str() :
                string("Result of test case has no nested boolean value")
            )
            :
            string("Test case has no nested type");
        
        return test_result(name_, location_, success, reason);
      }
    private:
      std::string _name;
      location _location;
      bool _success;
      std::string _reason;
    };
  }
}

#endif

