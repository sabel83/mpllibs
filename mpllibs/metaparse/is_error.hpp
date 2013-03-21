#ifndef MPLLIBS_METAPARSE_IS_ERROR_HPP
#define MPLLIBS_METAPARSE_IS_ERROR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/fail_tag.hpp>

#include <boost/mpl/tag.hpp>

#include <boost/type_traits/is_same.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class T>
    struct is_error :
      boost::is_same<
        fail_tag,
        typename boost::mpl::tag<typename T::type>::type
      >
    {};
  }
}

#endif

