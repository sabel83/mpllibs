#include <mpllibs/metatest/plaintext_report.h>
#include <mpllibs/metatest/test_driver.h>

#include <algorithm>
#include <iterator>

using namespace std;

namespace mpllibs {
namespace metatest {

bool plaintext_report(std::ostream &os_)
{
  test_driver &driver = test_driver::instance();

  os_ << "The following tests have been executed:" << endl;
    
  copy(driver.begin(), driver.end(),
      ostream_iterator<test_result>(os_, "  "));
      
  os_ << "========================" << std::endl;
  os_ << "Number of tests: " << driver.total_count() << endl;
  os_ << "Number of failures: " << driver.failure_count() << endl;

  return driver.failure_count() == 0;
}

} // namespace metatest
} // namespace mpllibs

