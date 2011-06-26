#ifndef MPLLIBS_METAMONAD_GET_DATA_HPP
#define MPLLIBS_METAMONAD_GET_DATA_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/tag.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class>
    struct get_data_impl;
    
    template <class E>
    struct get_data :
      boost::mpl::apply_wrap1<
        get_data_impl<typename boost::mpl::tag<typename E::type>::type>,
        typename E::type
      >
    {};
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  mpllibs::metamonad::get_data,
  "get_data"
);

#endif

