#ifndef MPLLIBS_METAPARSE_SOURCE_POSITION_HPP
#define MPLLIBS_METAPARSE_SOURCE_POSITION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/get_col.hpp>
#include <mpllibs/metaparse/get_line.hpp>

#include <mpllibs/metamonad/tmp_tag.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/char.hpp>
#include <boost/mpl/plus.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    struct source_position_tag :
      mpllibs::metamonad::tmp_tag<source_position_tag>
    {};
    
    template <class Line, class Col, class PrevChar>
    struct source_position
    {
      typedef source_position_tag tag;
      typedef source_position type;
      
      typedef Line line;
      typedef Col col;
      typedef PrevChar prev_char;
    };
    
    typedef
      source_position<
        boost::mpl::int_<1>,
        boost::mpl::int_<1>,
        boost::mpl::char_<0>
      >
      start;


    
    template <class T>
    struct get_col_impl;
    
    template <>
    struct get_col_impl<source_position_tag>
    {
      template <class P>
      struct apply : P::col {};
    };


    
    template <class T>
    struct get_line_impl;
    
    template <>
    struct get_line_impl<source_position_tag>
    {
      template <class P>
      struct apply : P::line {};
    };

    
    template <class T>
    struct get_prev_char_impl;
    
    template <>
    struct get_prev_char_impl<source_position_tag>
    {
      template <class P>
      struct apply : P::prev_char {};
    };
    
    
    template <class T>
    struct next_char_impl;
    
    template <>
    struct next_char_impl<source_position_tag>
    {
      template <class P, class Ch>
      struct apply :
        source_position<
          typename get_line<P>::type,
          typename boost::mpl::plus<
            typename get_col<P>::type,
            boost::mpl::int_<1>
          >::type,
          Ch
        >
      {};
    };



    template <class T>
    struct next_line_impl;
    
    template <>
    struct next_line_impl<source_position_tag>
    {
      template <class P, class Ch>
      struct apply :
        source_position<
          typename boost::mpl::plus<
            typename get_line<P>::type,
            boost::mpl::int_<1>
          >::type,
          boost::mpl::int_<1>,
          Ch
        >
      {};
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  3,
  mpllibs::metaparse::source_position,
  "source_position"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(mpllibs::metaparse::start, "start")

#endif

