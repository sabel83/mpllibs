#ifndef MPLLIBS_METATEST_SUITE_PATH_HPP
#define MPLLIBS_METATEST_SUITE_PATH_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include <list>

namespace mpllibs
{
  namespace metatest
  {
    class suite_path
    {
    private:
      typedef std::list<std::string> elements;
    public:
      typedef elements::const_iterator const_iterator;
      
      suite_path();
      suite_path(const std::string& p_);
      suite_path(const std::list<std::string>& p_);
      
      const_iterator begin() const;
      const_iterator end() const;
      
      suite_path operator()(const std::string& e_) const;
    private:
      elements _elements;
    };
  }
}

#endif

