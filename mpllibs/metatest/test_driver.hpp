#ifndef MPLLIBS_METATEST_TEST_DRIVER_HPP
#define MPLLIBS_METATEST_TEST_DRIVER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/config.hpp>
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
      MPLLIBS_METATEST_DECL static test_driver& instance();
      
      MPLLIBS_METATEST_DECL const test_suite& suite() const;

      MPLLIBS_METATEST_DECL void add(
        const suite_path& suite_,
        const test_result& result_
      );
    private:
      test_suite _suite;
    };
  }
}

#endif

