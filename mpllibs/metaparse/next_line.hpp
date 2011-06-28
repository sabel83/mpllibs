#ifndef MPLLIBS_METAPARSE_NEXT_LINE_HPP
#define MPLLIBS_METAPARSE_NEXT_LINE_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/tag.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P>
    struct next_line_impl;
    
    template <class P, class Ch>
    struct next_line :
      boost::mpl::apply_wrap2<
        next_line_impl<typename boost::mpl::tag<typename P::type>::type>,
        typename P::type,
        typename Ch::type
      >
    {
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "next_line<";
          mpllibs::metatest::to_stream_argument_list<P, Ch>::run(o);
          return o << ">";
        }
      };
    };
  }
}

#endif

