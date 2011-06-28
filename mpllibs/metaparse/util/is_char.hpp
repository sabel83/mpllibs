#ifndef MPLLIBS_METAPARSE_UTIL_IS_CHAR_HPP
#define MPLLIBS_METAPARSE_UTIL_IS_CHAR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/equal_to.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      template <class C>
      struct is_char
      {
        typedef is_char type;
        
        template <class S>
        struct apply : boost::mpl::equal_to<C, S> {};
        
        struct to_stream
        {
          static std::ostream& run(std::ostream& o)
          {
            o << "is_char<";
            mpllibs::metatest::to_stream_argument_list<C>::run(o);
            return o << ">";
          }
        };
      };
    }
  }
}

#endif

