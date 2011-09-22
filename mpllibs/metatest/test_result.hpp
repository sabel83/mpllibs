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
      ) :
        _name(name_),
        _location(location_),
        _success(success_),
        _reason(reason_)
      {}

      bool has_name() const
      {
        return _name != "";
      }
      
      const std::string& get_name() const
      {
        return _name;
      }

      const location& get_location() const
      {
        return _location;
      }
      
      bool success() const
      {
        return _success;
      }
      
      const std::string& get_reason() const
      {
        return _reason;
      }
      
      bool has_reason() const
      {
        return _reason != "";
      }
      
      template <class Pred>
      static test_result build(
        const location& location_,
        const std::string& name_
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

    inline std::ostream& operator<<(std::ostream& o_, const test_result& r_)
    {
      return o_
        << r_.get_location() << ": "
        << r_.get_name() << " "
        << (r_.success() ? "ok " : "failed ")
        << (r_.has_reason() ? "(" + r_.get_reason() + ")" : std::string());
    }
  }
}

#endif

