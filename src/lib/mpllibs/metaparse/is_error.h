#ifndef MPLLIBS_PARSER_IS_ERROR_H
#define MPLLIBS_PARSER_IS_ERROR_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/tag.hpp>

#include <boost/type_traits/is_same.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    struct error_tag;
  
    template <class t>
    struct is_error :
      boost::is_same<
        mpllibs::metaparse::error_tag,
        typename boost::mpl::tag<typename t::type>::type
      >
    {};
  }
}

#endif

