#include <mpllibs/metatest/xml_report.hpp>
#include <mpllibs/metatest/test_driver.hpp>

#include <algorithm>
#include <boost/lambda/lambda.hpp>

using namespace std;

namespace mpllibs {
namespace metatest {

bool xml_report(std::ostream &os_)
{
  os_ << "TODO" << endl;
  return true;
/*  using boost::lambda::_1;
  using boost::lambda::constant;

  test_driver &driver = test_driver::instance();

  os_ << "<summary>\n";

  os_ << "<caselist count=\""
      << driver.total_count()
      << "\" failed_count=\""
      << driver.failure_count()
      << "\">\n";

  for_each(driver.begin(), driver.end(),
      os_ << constant("<testcase description =\"") << _1 << "\"/>\n");

  os_ << "</caselist>\n";

  os_ << "</summary>\n";

  return driver.failure_count() == 0;*/
}

} // namespace metatest
} // namespace mpllibs

