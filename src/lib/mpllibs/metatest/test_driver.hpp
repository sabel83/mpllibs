#ifndef MPLLIBS_TEST_TEST_DRIVER_H
#define MPLLIBS_TEST_TEST_DRIVER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/has_type_value.hpp>
#include <mpllibs/metatest/get_type_value.hpp>
#include <mpllibs/metatest/has_type.hpp>
#include <mpllibs/metatest/test_result.hpp>
#include <mpllibs/metatest/to_stream.hpp>
#include <mpllibs/metatest/test_suite.hpp>

#include <boost/mpl/equal_to.hpp>

#include <boost/type_traits/is_same.hpp>

#include <list>
#include <iostream>
#include <sstream>

namespace mpllibs
{
  namespace metatest
  {
    class test_driver
    {
    public:
      template <class TestFunctor, bool ExpectedResult>
      static void run_test(
        const suite_path& suite_,
        const std::string& name_,
        const location& location_
      )
      {
        using std::ostringstream;
        using std::string;
        
        const bool has_t = has_type<TestFunctor>::type::value;
        
        const bool has_v = has_type_value<TestFunctor, bool>::type::value;
          
        const bool result =
          get_type_value<TestFunctor, boost::mpl::false_>::type::value;
        
        ostringstream s;
        to_stream<TestFunctor>::run(s);

        const bool success = has_t && has_v && result == ExpectedResult;

        const string reason =
          has_t ?
            (
              has_v ?
                s.str() :
                string("Result of test case has no nested boolean value")
            )
            :
            string("Test case has no nested type");
        
        test_driver::add(
          suite_,
          test_result(name_, location_, success, reason)
        );
      }
   
      static test_driver& instance();
      
      const test_suite& suite() const;
    private:
      test_suite _suite;
      
      static void add(const suite_path& suite_, const test_result& result_);
    };
  }
}

#endif

