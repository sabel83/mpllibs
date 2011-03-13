#ifndef MPLLIBS_PARSER_ACCEPT_H
#define MPLLIBS_PARSER_ACCEPT_H

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/get_remaining.h>
#include <mpllibs/metaparse/get_result.h>
#include <mpllibs/metaparse/get_position.h>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    struct accept_tag
    {
      typedef accept_tag type;
    };
  
    template <class result_, class s_, class source_position_>
    struct accept
    {
      typedef mpllibs::metaparse::accept_tag tag;
      typedef accept type;
      
      typedef result_ result;
      typedef s_ remaining;
      typedef source_position_ source_position;
    };
    
    
    
    template <class>
    struct get_result_impl;
    
    template <>
    struct get_result_impl<mpllibs::metaparse::accept_tag>
    {
      template <class a>
      struct apply : a::result {};
    };
    

    
    template <class>
    struct get_remaining_impl;
    
    template <>
    struct get_remaining_impl<mpllibs::metaparse::accept_tag>
    {
      template <class a>
      struct apply : a::remaining {};
    };
    


    template <class>
    struct get_position_impl;
    
    template <>
    struct get_position_impl<mpllibs::metaparse::accept_tag>
    {
      template <class a>
      struct apply : a::source_position {};
    };
  }

  namespace error
  {
    template <class t>
    struct to_stream_impl;
    
    template <>
    struct to_stream_impl<mpllibs::metaparse::accept_tag>
    {
      template <class e>
      struct apply
      {
        typedef apply type;
      
        static std::ostream& run(std::ostream& o_)
        {
          o_ << "accept<";
          mpllibs::error::to_stream_impl<
            typename mpllibs::metaparse::get_result<e>::type
          >::run(o_);
          o_ << ", ";
          mpllibs::error::to_stream_impl<
            typename mpllibs::metaparse::get_remaining<e>::type
          >::run(o_);
          o_ << ", ";
          mpllibs::error::to_stream_impl<
            typename mpllibs::metaparse::get_position<e>::type
          >::run(o_);
          return o_ << ">";
        }
      };
    };
  }
}

#endif

