#ifndef MPLLIBS_TEST_TEST_DRIVER_H
#define MPLLIBS_TEST_TEST_DRIVER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/test/has_type_value.h>
#include <mpllibs/test/get_type_value.h>
#include <mpllibs/test/get_value_member.h>
#include <mpllibs/test/has_value_member.h>
#include <mpllibs/test/has_type.h>
#include <mpllibs/test/TestResult.h>
#include <mpllibs/test/yes.h>
#include <mpllibs/test/no.h>

#include <boost/pool/detail/singleton.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/bind.hpp>

#include <list>
#include <algorithm>

namespace mpllibs
{
  namespace test
  {
    class TestDriver
    {
    private:
      typedef std::list<TestResult> ResultList;
    public:
      typedef ResultList::const_iterator const_iterator;
    
      ~TestDriver();
    
      template <class TestFunctor, bool expectedResult>
      void runTest(
        const mpllibs::test::TestSuite& suite_,
        const std::string& name_,
        const mpllibs::test::Location& location_
      )
      {
        const bool hasType = has_type<TestFunctor>::type::value;
        
        const bool hasValue = has_type_value<TestFunctor, bool>::type::value;
          
        const bool result =
          get_type_value<TestFunctor, boost::mpl::false_>::type::value;

        _results.push_back(
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
   
      ptrdiff_t failureCount() const
      {
        return
          std::count_if(
            _results.begin(),
            _results.end(),
            !boost::bind(&TestResult::success, _1)
          );
      }
      
      size_t totalCount() const
      {
        return _results.size();
      }
      
      static TestDriver& instance()
      {
        return boost::details::pool::singleton_default<TestDriver>::instance();
      }
      
      const_iterator begin() const
      {
        return _results.begin();
      }
      
      const_iterator end() const
      {
        return _results.end();
      }
    
      int main(int, char*[]) const
      {
        // Summary is printed in the destructor
        return this->failureCount() > 0 ? 1 : 0;
      }
    private:
      ResultList _results;
    };
    
    inline std::ostream& operator<<(std::ostream& out_, const TestDriver& d_)
    {
      out_ << "The following tests have been executed:" << std::endl;
    
      std::for_each(
        d_.begin(),
        d_.end(),
        std::cout << boost::lambda::constant("  ") << boost::lambda::_1
      );
      
      out_ << "========================" << std::endl;
      out_
        << "Number of tests: "
        << d_.totalCount()
        << std::endl;
      out_ << "Number of failures: " << d_.failureCount() << std::endl;
      
      return out_;
    }
    
    inline TestDriver::~TestDriver()
    {
      // Print summary in the destructor to make sure it's executed after
      // the tests
      std::cout << *this;
    }
  }
}

#endif

