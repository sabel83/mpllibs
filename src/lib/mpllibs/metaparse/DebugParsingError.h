#ifndef MPLLIBS_PARSER_DEBUG_PARSING_ERROR_H
#define MPLLIBS_PARSER_DEBUG_PARSING_ERROR_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/error.h>

#include <mpllibs/metatest/to_stream.h>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/string.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p, class s>
    class DebugParsingError
    {
    public:
      DebugParsingError()
      {
        using std::cout;
        using std::endl;
        using boost::mpl::c_str;
      
        typedef
          Run<typename boost::mpl::apply<p, s, mpllibs::metaparse::start>::type>
          Runner;
          
        cout << "Compile-time parsing results" << endl;
        cout << "----------------------------" << endl;
        cout << "Input text:" << endl;
        cout << c_str<s>::type::value << endl;
        cout << endl;
        Runner::run();
        
        exit(0);
      }
    
    private:
      template <class result>
      struct RunError
      {
        static void run()
        {
          using std::cout;
          using std::endl;
          using mpllibs::metatest::to_stream;
          
          cout << "Parsing failed:" << endl;
          to_stream<result>::run(cout);
          cout << endl;
        }
      };
      
      template <class result>
      struct RunNoError
      {
        static void run()
        {
          using std::cout;
          using std::endl;
          using mpllibs::metaparse::get_remaining;
          using boost::mpl::c_str;
          
          typedef typename get_remaining<result>::type RemainingString;
          
          cout
            << "Parsing was successful. Remaining string is:" << endl
            << c_str<RemainingString>::type::value << endl;
        }
      };

      template <class result>
      struct Run :
        boost::mpl::if_<
          typename mpllibs::metaparse::is_error<result>::type,
          RunError<result>,
          RunNoError<result>
        >::type
      {};
    };

    // Special case to handle when DebugParsingError is used with build_parser
    // (it shouldn't be)
    template <class>
    struct build_parser;
    
    template <class p, class s>
    struct DebugParsingError<mpllibs::metaparse::build_parser<p>, s> :
      mpllibs::metaparse::DebugParsingError<p, s>
    {};
  }
}

#endif


