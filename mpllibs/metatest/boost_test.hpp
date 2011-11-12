#ifndef MPLLIBS_METATEST_BOOST_TEST_HPP
#define MPLLIBS_METATEST_BOOST_TEST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test_result.hpp>
#include <boost/test/unit_test.hpp>

namespace mpllibs
{
  namespace metatest
  {
    template <class Pred>
    void meta_warn(const location& location_, const std::string& name_)
    {
      const test_result result = test_result::build<Pred>(location_, name_);
      BOOST_WARN_MESSAGE(result.success(), result);
    }

    template <class Pred>
    void meta_warn(const location& location_)
    {
      const test_result result = test_result::build<Pred>(location_);
      BOOST_WARN_MESSAGE(result.success(), result);
    }

    template <class Pred>
    void meta_check(const location& location_, const std::string& name_)
    {
      const test_result result = test_result::build<Pred>(location_, name_);
      BOOST_CHECK_MESSAGE(result.success(), result);
    }

    template <class Pred>
    void meta_check(const location& location_)
    {
      const test_result result = test_result::build<Pred>(location_);
      BOOST_CHECK_MESSAGE(result.success(), result);
    }

    template <class Pred>
    void meta_require(const location& location_, const std::string& name_)
    {
      const test_result result = test_result::build<Pred>(location_, name_);
      BOOST_REQUIRE_MESSAGE(result.success(), result);
    }

    template <class Pred>
    void meta_require(const location& location_)
    {
      const test_result result = test_result::build<Pred>(location_);
      BOOST_REQUIRE_MESSAGE(result.success(), result);
    }
  }
}

#endif

