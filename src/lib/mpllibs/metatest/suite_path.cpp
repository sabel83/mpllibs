// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/suite_path.h>

#include <cassert>

using mpllibs::metatest::suite_path;

using std::string;

suite_path::suite_path()
{}

suite_path::suite_path(const std::string& p_) :
  _elements(1, p_)
{}

suite_path::suite_path(const std::list<std::string>& p_) :
  _elements(p_)
{}

suite_path::const_iterator suite_path::begin() const
{
  return _elements.begin();
}

suite_path::const_iterator suite_path::end() const
{
  return _elements.end();
}

suite_path suite_path::operator()(const std::string& e_) const
{
  suite_path result(*this);
  result._elements.push_back(e_);
  return result;
}

