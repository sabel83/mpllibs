#ifndef MPLLIBS_METAPARSE_V2_ERROR_UNPAIRED_HPP
#define MPLLIBS_METAPARSE_V2_ERROR_UNPAIRED_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/vector.hpp>

#include <iostream>
#include <string>
#include <sstream>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace error
      {
        template <int Line, int Col, class Msg = boost::mpl::na>
        struct unpaired
        {
          typedef unpaired type;

          static std::string get_value()
          {
            std::ostringstream s;
            s << Msg::get_value() << " (see " << Line << ":" << Col << ")";
            return s.str();
          }
        };

        template <int Line, int Col>
        struct unpaired<Line, Col, boost::mpl::na>
        {
          typedef unpaired type;

          template <class Msg = boost::mpl::na>
          struct apply : unpaired<Line, Col, Msg> {};
        };
      }
    }
  }
}

#endif

