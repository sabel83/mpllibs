#ifndef MPLLIBS_TEST_TEST_DRIVER_H
#define MPLLIBS_TEST_TEST_DRIVER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/has_type_value.h>
#include <mpllibs/metatest/get_type_value.h>
#include <mpllibs/metatest/has_type.h>
#include <mpllibs/metatest/test_result.h>
#include <mpllibs/metatest/to_stream.h>

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
    private:
      typedef std::list<test_result> result_list;
    public:
      typedef result_list::const_iterator const_iterator;
    
      ~test_driver();
    
      template <class TestFunctor, bool ExpectedResult>
      static void run_test(
        const test_suite& suite_,
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

        test_driver::add(
          test_result(
            suite_,
            name_,
            location_,
            has_t && has_v && result == ExpectedResult,
            has_t ?
              (
                has_v ?
                  s.str() :
                  string("Result of test case has no nested boolean value")
              )
              :
              string("Test case has no nested type")
          )
        );
      }
   
      ptrdiff_t failure_count() const;
      
      size_t total_count() const;
      
      static test_driver& instance();
      
      const_iterator begin() const;
      const_iterator end() const;
    
      int main(int, char*[]) const;
    private:
      result_list _results;
      
      static void add(const test_result& result_);
    };
    
    std::ostream& operator<<(std::ostream& out_, const test_driver& d_);
  }
}

#endif

