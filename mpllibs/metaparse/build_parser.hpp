#ifndef MPLLIBS_METAPARSE_BUILD_PARSER_HPP
#define MPLLIBS_METAPARSE_BUILD_PARSER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P>
    struct build_parser
    {
      typedef build_parser type;
      
      template <class S>
      struct apply : get_result<boost::mpl::apply<P, S, start> > {};

      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "build_parser<";
          mpllibs::metatest::to_stream_argument_list<P>::run(o);
          return o << ">";
        }
      };
    };
  }
}

#endif

