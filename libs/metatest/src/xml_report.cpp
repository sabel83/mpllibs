// Copyright Endre Tamas Sajo (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/xml_report.hpp>
#include <mpllibs/metatest/test_driver.hpp>

#include <algorithm>
#include <boost/lambda/lambda.hpp>

using namespace std;

namespace mpllibs {
namespace metatest {

namespace
{
  void display(ostream& out_, const string&, const test_suite& f_)
  {
    using std::endl;
    
    for (
      test_suite::suite_map::const_iterator
        i = f_.suites().begin(),
        e = f_.suites().end();
      i != e;
      ++i
    )
    {
      out_ << "<suite name=\"" << i->first << "\">\n";
      display(out_, "", i->second);
      out_ << "</suite>\n";
    }
    
    for (
      test_suite::result_list::const_iterator
        i = f_.results().begin(),
        e = f_.results().end();
      i != e;
      ++i
    )
    {
      out_
        << "<case name=\"" << i->get_name() << "\" "
        << "status=\"" << (i->success() ? "ok" : "fail")  << "\">\n";

      if (i->has_reason())
      {
        const std::string &reason = i->get_reason();

        for (std::string::const_iterator it = reason.begin();
            it != reason.end(); ++it)
        {
          if ('<' == *it) out_ << "&lt;";
          else if ('>' == *it) out_ << "&gt;";
          else if ('&' == *it) out_ << "&amp;";
          else out_ << *it;
        }
      }

      out_ << "</case>\n";
    }
  }
}

bool xml_report(std::ostream& out_)
{
  using std::endl;

  const test_suite& suite = test_driver::instance().suite();

  out_
    << "<summary "
    << "test_count=\"" << suite.count() << "\" "
    << "failed_test_count=\"" << suite.count() << "\""
    << ">\n";
  
  display(out_, "", suite);
      
  out_ << "</summary>\n";

  return suite.failure_count() == 0;
}

} // namespace metatest
} // namespace mpllibs

