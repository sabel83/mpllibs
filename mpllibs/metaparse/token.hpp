#ifndef MPLLIBS_METAPARSE_TOKEN_HPP
#define MPLLIBS_METAPARSE_TOKEN_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/space.hpp>
#include <mpllibs/metaparse/any.hpp>
#include <mpllibs/metaparse/first_of.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <boost/mpl/void.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P>
    struct token : first_of<P, any<space> >
    {
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "token<";
          mpllibs::metatest::to_stream_argument_list<P>::run(o);
          return o << ">";
        }
      };
    };
  }
}

#endif

