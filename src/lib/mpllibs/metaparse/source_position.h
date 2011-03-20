#ifndef MPLLIBS_PARSER_SOURCE_POSITION_H
#define MPLLIBS_PARSER_SOURCE_POSITION_H

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/get_col.h>
#include <mpllibs/metaparse/get_line.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/integral_c.hpp>
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
    
    template <class line_, class col_, class prev_char_>
    struct source_position
    {
      typedef mpllibs::metaparse::source_position_tag tag;
      typedef source_position type;
      
      typedef line_ line;
      typedef col_ col;
      typedef prev_char_ prev_char;
    };
    
    typedef
      mpllibs::metaparse::source_position<
        boost::mpl::int_<1>,
        boost::mpl::int_<1>,
        boost::mpl::integral_c<char, 0>
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
    struct get_prev_char_impl;
    
    template <>
    struct get_prev_char_impl<mpllibs::metaparse::source_position_tag>
    {
      template <class p>
      struct apply : p::prev_char {};
    };
    
    
    template <class t>
    struct next_char_impl;
    
    template <>
    struct next_char_impl<mpllibs::metaparse::source_position_tag>
    {
      template <class p, class ch>
      struct apply :
        mpllibs::metaparse::source_position<
          mpllibs::metaparse::get_line<p>,
          boost::mpl::plus<
            typename mpllibs::metaparse::get_col<p>::type,
            boost::mpl::int_<1>
          >,
          ch
        >
      {};
    };



    template <class t>
    struct next_line_impl;
    
    template <>
    struct next_line_impl<mpllibs::metaparse::source_position_tag>
    {
      template <class p, class ch>
      struct apply :
        mpllibs::metaparse::source_position<
          boost::mpl::plus<
            typename mpllibs::metaparse::get_line<p>::type,
            boost::mpl::int_<1>
          >,
          boost::mpl::int_<1>,
          ch
        >
      {};
    };
  }
  
  namespace metatest
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
          using mpllibs::metaparse::get_line;
          using mpllibs::metaparse::get_col;
          
          return
            o_
              << "line " << get_line<sp>::type::value
              << ", col " << get_col<sp>::type::value;
        }
      };
    };
  }
}

#endif

