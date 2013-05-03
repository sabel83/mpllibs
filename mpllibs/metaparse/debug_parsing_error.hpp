#ifndef MPLLIBS_METAPARSE_DEBUG_PARSING_ERROR_HPP
#define MPLLIBS_METAPARSE_DEBUG_PARSING_ERROR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/is_error.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/string.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class S>
    class debug_parsing_error
    {
    public:
      debug_parsing_error()
      {
        using std::cout;
        using std::endl;
        using boost::mpl::c_str;
        using boost::mpl::apply;
      
        typedef display<typename apply<P, S, start>::type> runner;
          
        cout << "Compile-time parsing results" << endl;
        cout << "----------------------------" << endl;
        cout << "Input text:" << endl;
        cout << c_str<S>::type::value << endl;
        cout << endl;
        runner::run();
        
        exit(0);
      }
    
      typedef debug_parsing_error type;
    private:
      template <class Result>
      struct display_error
      {
        static void run()
        {
          using std::endl;
          using mpllibs::metaparse::get_line;
          using mpllibs::metaparse::get_col;
          
          typedef typename Result::type R;

          std::cout
            << "Parsing failed:" << endl
            << "line " << get_line<typename R::source_position>::type::value
            << ", col " << get_col<typename R::source_position>::type::value
            << ": "
            << R::message::type::get_value() << endl;
        }
      };
      
      template <class Result>
      struct display_no_error
      {
        static void run()
        {
          using std::cout;
          using std::endl;
          using boost::mpl::c_str;
          
          typedef typename get_remaining<Result>::type remaining_string;
          
          cout
            << "Parsing was successful. Remaining string is:" << endl
            << c_str<remaining_string>::type::value << endl;
        }
      };

      template <class Result>
      struct display :
        boost::mpl::if_<
          typename is_error<Result>::type,
          display_error<Result>,
          display_no_error<Result>
        >::type
      {};
    };

    // Special case to handle when DebugParsingError is used with build_parser
    // (it shouldn't be)
    template <class>
    struct build_parser;
    
    template <class P, class S>
    class debug_parsing_error<build_parser<P>, S> :
      debug_parsing_error<P, S>
    {};
  }
}

#endif


