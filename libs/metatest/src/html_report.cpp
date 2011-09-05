// Copyright Endre Tamas Sajo (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/html_report.hpp>
#include <mpllibs/metatest/test_driver.hpp>

#include <boost/lambda/lambda.hpp>

#include <string>
#include <algorithm>

using namespace std;

namespace mpllibs {
namespace metatest {

namespace
{
  template <class InputIt>
  void escaped_output(ostream& out_, InputIt begin_, InputIt end_)
  {
    for (InputIt c = begin_; c != end_; ++c)
    {
      switch (*c)
      {
        case '<': out_ << "&lt;"; break;
        case '>': out_ << "&gt;"; break;
        case '&': out_ << "&amp;"; break;
        default: out_ << *c;
      }
    }
  }
  
  class indent
  {
  public:
    explicit indent(int depth_) :
      _s(depth_ * indent_spaces, ' ')
    {}

    indent operator+(int n_) const
    {
      return indent(_s + string(n_ * indent_spaces, ' '));
    }

    friend ostream& operator<<(ostream& out_, indent i_)
    {
      return out_ << i_._s;
    }
  private:
    static const int indent_spaces = 2;
    string _s;

    explicit indent(string s_) :
      _s(s_)
    {}
  };

  const char* success_or_failure_html(bool success_)
  {
    return
      success_ ?
        " <span class=\"ok\">OK</span>"
        : " <span class=\"fail\">FAILED</span>";
  }

  void display(
    ostream& out_,
    const string& name_,
    const test_suite& f_,
    indent indent_
  )
  {
    const indent i(indent_);
    const indent ii(name_ == "" ? indent_ : indent_ + 1);

    if (name_ != "")
    {
      out_ << i << "<p class=\"caseName\">";
      escaped_output(out_, name_.begin(), name_.end());
      out_
        << success_or_failure_html(f_.failure_count() == 0) << "</p>\n"
        << i << "<div class=\"caseDetails\">\n"
      ;
    }
    
    for (test_suite::suite_map::const_iterator s = f_.suites().begin();
        s != f_.suites().end();
        ++s)
    {
      display(out_, s->first, s->second, ii);
    }

    for (test_suite::result_list::const_iterator j = f_.results().begin();
        j != f_.results().end();
        ++j)
    {
      out_ << ii << "<p class=\"caseName\">";
      escaped_output(out_, j->get_name().begin(), j->get_name().end());
      out_ << success_or_failure_html(j->success()) << "</p>\n";

      out_ << ii << "<div class=\"caseDetails\">";

      if (j->has_reason())
      {
        const string &reason = j->get_reason();
        escaped_output(out_, reason.begin(), reason.end());
      }

      out_ << "</div>\n";
    }

    if (name_ != "")
    {
      out_ << i << "</div>\n";
    }
  }
}

bool html_report(std::ostream& out_)
{
  using std::endl;

  const test_suite& suite = test_driver::instance().suite();
  const string jquery = "jquery.js";

  const indent i(1);
  const indent ii(2);
  const indent iii(3);
  const indent iiii(4);

  out_
    <<     "<!doctype html>\n"
           "<html>\n"
    << i << "<head>\n"
    << i << "<title>Metatest report</title>\n"
    << i << "<script src=\"" << jquery << "\"></script>\n"
    << i << "<script>" "<!--\n"
    << ii << "$(document).ready(function() {\n"
    << iii << "$($(\"div.caseDetails\").get().reverse()).toggle();\n"
    << iii << "$(\"p.caseName\").click(function() {\n"
    << iiii << "$(this).next(\"div.caseDetails\").slideToggle();\n"
    << iii << "});\n"
    << ii << "});\n"
    << i << "-->" "</script>\n"
    << i << "<style type=\"text/css\">" "<!--\n"
    << ii << "p.caseName {\n"
    << iii << "font-family:monospace;\n"
    << iii << "cursor:pointer;\n"
    << iii << "background:#ddd;\n"
    << ii << "}\n"
    << ii << "p.caseName:hover { text-decoration:underline; }\n"
    << ii << "span.ok { color:#0c0; }\n"
    << ii << "span.fail { color:#f00; }\n"
    << ii << "div.caseDetails {\n"
    << iii << "font-family:monospace;\n"
    << iii << "margin-left:30px\n"
    << ii << "}\n"
    << i << "-->" "</style>\n"
    <<     "</head>\n"
           "<body>\n"
    << i << "<h1>Metatest report</h1>\n"
  ;

  display(out_, "", suite, i);

  out_
    << "</body>\n"
       "</html>\n"
    ;

  return suite.failure_count() == 0;
}

} // namespace metatest
} // namespace mpllibs

