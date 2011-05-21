// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test_suite.h>

#include <boost/lambda/lambda.hpp>
#include <boost/bind.hpp>

#include <algorithm>

using mpllibs::metatest::test_suite;

size_t test_suite::failure_count() const
{
  using std::count_if;
  using boost::bind;
  
  const size_t this_suite =
    static_cast<size_t>(
      count_if(
        _results.begin(),
        _results.end(),
        !bind(&test_result::success, _1)
      )
    );
  
  size_t children = 0;
  for (
    suite_map::const_iterator i = _suites.begin(), e = _suites.end();
    i != e;
    ++i
  )
  {
    children += i->second.failure_count();
  }
  
  return this_suite + children;
}

size_t test_suite::count() const
{
  using std::count_if;
  using boost::bind;
  
  const size_t this_suite = _results.size();
  
  size_t children = 0;
  for (
    suite_map::const_iterator i = _suites.begin(), e = _suites.end();
    i != e;
    ++i
  )
  {
    children += i->second.count();
  }
  
  return this_suite + children;
}
   
const test_suite::suite_map& test_suite::suites() const
{
  return _suites;
}

const test_suite::result_list& test_suite::results() const
{
  return _results;
}

void test_suite::add(
  suite_path::const_iterator begin_,
  suite_path::const_iterator end_,
  const test_result& result_
)
{
  if (begin_ == end_)
  {
    _results.push_back(result_);
  }
  else
  {
    suite_path::const_iterator tail_begin(begin_);
    ++tail_begin;
    _suites[*begin_].add(tail_begin, end_, result_);
  }
}




