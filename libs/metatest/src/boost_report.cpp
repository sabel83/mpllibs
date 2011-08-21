// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/boost_report.hpp>

#include <mpllibs/metatest/test_driver.hpp>
#include <mpllibs/metatest/test_suite.hpp>

#include <boost/test/parameterized_test.hpp>

using boost::unit_test::framework::master_test_suite;

using mpllibs::metatest::test_driver;
using mpllibs::metatest::test_result;

using boost::test_tools::predicate_result;

using std::string;

namespace
{
  class report_metatest
  {
  public:
    report_metatest(test_result result) : _result(metatest_predicate(result)) {}
  
    void operator()() const
    {
      // I use a reference to "format" the error report
      const predicate_result& compile_time_test = _result;
      BOOST_CHECK(compile_time_test);
    }
  private:
    predicate_result _result;
  
    static predicate_result metatest_predicate(test_result r_)
    {
      if (r_.success())
      {
        return true;
      }
      else
      {
        predicate_result res(false);
        res.message() << r_.get_location();
        if (r_.has_reason())
        {
          res.message() << ": " << r_.get_reason();
        }
        return res;
      }
    }
  };

  boost::unit_test::test_suite* build_metatest_test_suite(
    const string& name_,
    const mpllibs::metatest::test_suite& suite_
  )
  {
    using boost::unit_test::make_test_case;
    using boost::unit_test::callback0;

    boost::unit_test::test_suite* s = BOOST_TEST_SUITE(name_);
    
    for (
      mpllibs::metatest::test_suite::suite_map::const_iterator
        i = suite_.suites().begin(), e = suite_.suites().end();
      i != e;
      ++i
    )
    {
      s->add(build_metatest_test_suite(i->first, i->second));
    }
    
    for (
      mpllibs::metatest::test_suite::result_list::const_iterator
        i = suite_.results().begin(), e = suite_.results().end();
      i != e;
      ++i
    )
    {
      s->add(make_test_case(callback0<>(report_metatest(*i)), i->get_name()));
    }
    
    return s;
  }
}

boost::unit_test::test_suite* mpllibs::metatest::build_metatest_test_suite(
  const string& name_
)
{
  return ::build_metatest_test_suite(name_, test_driver::instance().suite());
}


