// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/plaintext_report.h>

#include <ostream>

int main()
{
  using mpllibs::metatest::plaintext_report;
  using mpllibs::metatest::test_driver;

  return plaintext_report(std::cout) ? 0 : 1;
}

