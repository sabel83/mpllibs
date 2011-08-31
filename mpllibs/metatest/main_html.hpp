#ifndef MPLLIBS_METATEST_MAIN_HTML_HPP
#define MPLLIBS_METATEST_MAIN_HTML_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <mpllibs/metatest/html_report.hpp>

int main()
{
  mpllibs::metatest::html_report(std::cout);
}

#endif

