#ifndef MPLLIBS_METATEST_TEST_DRIVER_HPP
#define MPLLIBS_METATEST_TEST_DRIVER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test_result.hpp>
#include <mpllibs/metatest/test_suite.hpp>

#include <boost/mpl/equal_to.hpp>

#include <boost/type_traits/is_same.hpp>

#include <list>

namespace mpllibs
{
  namespace metatest
  {
    class test_driver
    {
    public:
      template <class Pred>
      static void run_test(
        const suite_path& suite_,
        const std::string& name_,
        const location& location_
      )
      {
        test_driver::add(suite_, test_result::build<Pred>(name_, location_));
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

