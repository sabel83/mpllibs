#ifndef MPLLIBS_PARSER_SOURCE_POSITION_H
#define MPLLIBS_PARSER_SOURCE_POSITION_H

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/get_col.h>
#include <mpllibs/metaparse/get_line.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/plus.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    struct source_position_tag
    {
      typedef source_position_tag type;
    };
    
    template <class line_, class col_>
    struct source_position
    {
      typedef mpllibs::metaparse::source_position_tag tag;
      typedef source_position type;
      
      typedef line_ line;
      typedef col_ col;
    };
    
    typedef
      mpllibs::metaparse::source_position<
        boost::mpl::int_<1>,
        boost::mpl::int_<1>
      >
      start;


    
    template <class t>
    struct get_col_impl;
    
    template <>
    struct get_col_impl<mpllibs::metaparse::source_position_tag>
    {
      template <class p>
      struct apply : p::col {};
    };


    
    template <class t>
    struct get_line_impl;
    
    template <>
    struct get_line_impl<mpllibs::metaparse::source_position_tag>
    {
      template <class p>
      struct apply : p::line {};
    };
    
    
    
    template <class t>
    struct next_char_impl;
    
    template <>
    struct next_char_impl<mpllibs::metaparse::source_position_tag>
    {
      template <class p>
      struct apply :
        mpllibs::metaparse::source_position<
          mpllibs::metaparse::get_line<p>,
          boost::mpl::plus<
            typename mpllibs::metaparse::get_col<p>::type,
            boost::mpl::int_<1>
          >
        >
      {};
    };



    template <class t>
    struct next_line_impl;
    
    template <>
    struct next_line_impl<mpllibs::metaparse::source_position_tag>
    {
      template <class p>
      struct apply :
        mpllibs::metaparse::source_position<
          boost::mpl::plus<
            typename mpllibs::metaparse::get_line<p>::type,
            boost::mpl::int_<1>
          >,
          boost::mpl::int_<1>
        >
      {};
    };
  }
  
  namespace error
  {
    template <class t>
    struct to_stream_impl;
    
    template <>
    struct to_stream_impl<mpllibs::metaparse::source_position_tag>
    {
      template <class sp>
      struct apply
      {
        typedef apply type;
      
        static std::ostream& run(std::ostream& o_)
        {
          o_ << "line ";
          mpllibs::error::to_stream_impl<
            typename mpllibs::metaparse::get_line<sp>::type
          >::run(o_);
          o_ << ", col ";
          mpllibs::error::to_stream_impl<
            typename mpllibs::metaparse::get_col<sp>::type
          >::run(o_);
          return o_;
        }
      };
    };
  }
}

#endif

