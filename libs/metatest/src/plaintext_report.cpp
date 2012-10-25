#define MPLLIBS_METATEST_SOURCE

#include <mpllibs/metatest/plaintext_report.hpp>
#include <mpllibs/metatest/test_driver.hpp>

#include <algorithm>
#include <iterator>

using namespace std;

namespace mpllibs {
namespace metatest {

namespace
{
  void display(ostream& out_, const string& path_, const test_suite& f_)
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
      display(out_, path_ + i->first + "::", i->second);
    }
    
    for (
      test_suite::result_list::const_iterator
        i = f_.results().begin(),
        e = f_.results().end();
      i != e;
      ++i
    )
    {
      out_ << "  " << path_ << i->get_name() << ": ";
      if (i->success())
      {
        out_ << "OK";
      }
      else
      {
        out_ << "FAIL (" << i->get_location() << ")";
        if (i->has_reason())
        {
          out_ << endl << "\t" << i->get_reason();
        }
      }
      out_ << endl;
    }
  }
}

bool plaintext_report(std::ostream& out_)
{
  using std::endl;

  const test_suite& suite = test_driver::instance().suite();

  out_ << "The following tests have been executed:" << endl;
  
  display(out_, "", suite);
      
  out_ << "========================" << endl;
  out_ << "Number of tests: " << suite.count() << endl;
  out_ << "Number of failures: " << suite.failure_count() << endl;
      
  return suite.failure_count() == 0;
}

} // namespace metatest
} // namespace mpllibs

