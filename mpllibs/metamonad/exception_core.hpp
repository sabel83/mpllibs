#ifndef MPLLIBS_METAMONAD_EXCEPTION_CORE_HPP
#define MPLLIBS_METAMONAD_EXCEPTION_CORE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/data.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>

#include <string>
#include <sstream>
#include <iostream>

namespace mpllibs
{
  namespace metamonad
  {
    struct exception_tag : tmp_tag<exception_tag> {};

    template <class Reason = boost::mpl::void_>
    struct exception
    {
      typedef exception<typename Reason::type> type;
      typedef algebraic_data_type_tag tag;

      static std::string get_value()
      {
        std::ostringstream s;
        s << "exception<" << Reason::get_value() << ">";
        return s.str();
      }

      static const std::string value;
    };

    template <class Reason>
    const std::string exception<Reason>::value = exception<Reason>::get_value();

    // Currying
    template <>
    struct exception<boost::mpl::void_> :
      tmp_value<exception<boost::mpl::void_>, tag_tag>
    {
      template <class Reason>
      struct apply : exception<Reason> {};
    };
  }
}

#endif

