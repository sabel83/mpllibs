#ifndef MPLLIBS_TEST_TEST_FIXTURE_H
#define MPLLIBS_TEST_TEST_FIXTURE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/suite_path.h>
#include <mpllibs/metatest/test_result.h>

#include <string>
#include <map>
#include <list>
#include <iosfwd>

namespace mpllibs
{
  namespace metatest
  {
    class test_suite
    {
    public:
      typedef std::map<std::string, test_suite> suite_map;
      typedef std::list<test_result> result_list;
      
      void add(
        suite_path::const_iterator begin_,
        suite_path::const_iterator end_,
        const test_result& result_
      );
      
      size_t failure_count() const;
      size_t count() const;
      
      const suite_map& suites() const;
      const result_list& results() const;
    private:
      suite_map _suites;
      result_list _results;
    };
  }
}

#endif

