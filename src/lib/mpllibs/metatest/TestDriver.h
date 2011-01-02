#ifndef MPLLIBS_TEST_TEST_DRIVER_H
#define MPLLIBS_TEST_TEST_DRIVER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/has_type_value.h>
#include <mpllibs/metatest/get_type_value.h>
#include <mpllibs/metatest/has_type.h>
#include <mpllibs/metatest/TestResult.h>

#include <list>

namespace mpllibs
{
  namespace metatest
  {
    class TestDriver
    {
    private:
      typedef std::list<TestResult> ResultList;
    public:
      typedef ResultList::const_iterator const_iterator;
    
      ~TestDriver();
    
      template <class TestFunctor, bool expectedResult>
      static void runTest(
        const mpllibs::metatest::TestSuite& suite_,
        const std::string& name_,
        const mpllibs::metatest::Location& location_
      )
      {
        const bool hasType =
          mpllibs::metatest::has_type<TestFunctor>::type::value;
        
        const bool hasValue =
          mpllibs::metatest::has_type_value<TestFunctor, bool>::type::value;
          
        const bool result =
          mpllibs::metatest::get_type_value<
            TestFunctor,
            boost::mpl::false_
          >::type::value;

        mpllibs::metatest::TestDriver::add(
          TestResult(
            suite_,
            name_,
            location_,
            hasType && hasValue && result == expectedResult,
            hasType ?
              (hasValue?"":"Result of test case has no nested boolean value") :
              "Test case has no nested type"
          )
        );
      }
   
      ptrdiff_t failureCount() const;
      
      size_t totalCount() const;
      
      static TestDriver& instance();
      
      const_iterator begin() const;
      const_iterator end() const;
    
      int main(int, char*[]) const;
    private:
      ResultList _results;
      
      static void add(const TestResult& result_);
    };
    
    std::ostream& operator<<(std::ostream& out_, const TestDriver& d_);
  }
}

#endif

