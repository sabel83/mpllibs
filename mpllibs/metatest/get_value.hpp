#ifndef MPLLIBS_METATEST_GET_VALUE_HPP
#define MPLLIBS_METATEST_GET_VALUE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/has_value.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace metatest
  {
    template <class T, class Default>
    struct get_value :
      boost::mpl::eval_if<typename has_value<T, bool>::type, T, Default>
    {
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "get_value<";
          to_stream_argument_list<T, Default>::run(o);
          return o << ">";
        }
      };
    };
  }
}

#endif

