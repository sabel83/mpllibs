#ifndef MPLLIBS_TEST_TEST_DRIVER_H
#define MPLLIBS_TEST_TEST_DRIVER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/test/TestResult.h>

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
    
      template <class TestFunctor, bool result>
      void runTest(
        const std::string& name_,
        const std::string& filename_,
        int lineNumber_
      )
      {
        _results.push_back(
          TestResult(
            name_,
            filename_,
            lineNumber_,
            TestFunctor::type::value == result
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

