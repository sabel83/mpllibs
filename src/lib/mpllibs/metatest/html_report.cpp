// Copyright Endre Tamas Sajo (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/html_report.hpp>
#include <mpllibs/metatest/test_driver.hpp>

#include <algorithm>
#include <boost/lambda/lambda.hpp>

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
      out_ << "<p class=\"caseName\">"
           <<   path_ << i->get_name()
           <<   (i->success()
                   ? " <span class=\"ok\">OK</span>"
                   : " <span class=\"fail\">FAIL</span>")
           << "</p>"
      ;

      out_ << "<div class=\"caseDetails\">";

      if (i->has_reason())
      {
        const std::string &reason = i->get_reason();

        for (std::string::const_iterator it = reason.begin();
            it != reason.end();
            ++it)
        {
          if ('<' == *it)      out_ << "&lt;";
          else if ('>' == *it) out_ << "&gt;";
          else if ('&' == *it) out_ << "&amp;";
          else out_ << *it;
        }
      }

      out_ << "</div>";
    }
  }
}

bool html_report(std::ostream& out_)
{
  using std::endl;

  const test_suite& suite = test_driver::instance().suite();
  const std::string jquery = "jquery.js";

  out_ << "<!doctype html>"
          "<html>"
            "<head>"
              "<title>Metatest report</title>"
              "<script src=\"" << jquery << "\"></script>"
              "<script>"
                "$(document).ready(function() {"
                  "$(\"div.caseDetails\").toggle();"
                  "$(\"p.caseName\").click(function() {"
                    "$(this).next(\"div.caseDetails\").slideToggle();"
                  "});"
                "});"
              "</script>"
              "<style type=\"text/css\">"
                "<!--"
                  "p.caseName {"
                    "font-family:monospace;"
                    "font-size:120%;"
                    "cursor:pointer;"
                    "background:#ddd;"
                  "} "
                  "p.caseName:hover { text-decoration:underline; } "
                  "span.ok { color:#0c0; } "
                  "span.fail { color:#f00; } "
                  "div.caseDetails {"
                    "font-family:monospace;"
                    "font-size:120%;"
                    "margin-left:30px"
                  "}"
                "-->"
              "</style>"
            "</head>"
            "<body>"
    ;

  display(out_, "", suite);

  out_ <<   "</body>"
          "</html>"
    ;

  return out_;
}

} // namespace metatest
} // namespace mpllibs

