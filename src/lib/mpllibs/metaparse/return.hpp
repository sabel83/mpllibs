#ifndef MPLLIBS_PARSER_RETURN_H
#define MPLLIBS_PARSER_RETURN_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/get_remaining.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_position.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    struct accept_tag
    {
      typedef accept_tag type;
    };
    
    template <class C>
    struct return_
    {
      template <class S, class Pos>
      struct apply
      {
        typedef accept_tag tag;
        typedef apply type;
  
        typedef C result;
        typedef S remaining;
        typedef Pos source_position;
      };
    };
    
    
    
    template <class>
    struct get_result_impl;
    
    template <>
    struct get_result_impl<accept_tag>
    {
      template <class A>
      struct apply : A::result {};
    };
    

    
    template <class>
    struct get_remaining_impl;
    
    template <>
    struct get_remaining_impl<accept_tag>
    {
      template <class A>
      struct apply : A::remaining {};
    };
    


    template <class>
    struct get_position_impl;
    
    template <>
    struct get_position_impl<accept_tag>
    {
      template <class A>
      struct apply : A::source_position {};
    };
  }

  namespace error
  {
    template <class T>
    struct to_stream_impl;
    
    template <>
    struct to_stream_impl<mpllibs::metaparse::accept_tag>
    {
      template <class E>
      struct apply
      {
        typedef apply type;
      
        static std::ostream& run(std::ostream& o_)
        {
          typedef typename mpllibs::metaparse::get_result<E>::type result;
          typedef typename mpllibs::metaparse::get_remaining<E>::type remaining;
          typedef typename mpllibs::metaparse::get_position<E>::type position;
        
          o_ << "accept<";
          mpllibs::error::to_stream_impl<result>::run(o_);
          o_ << ", ";
          mpllibs::error::to_stream_impl<remaining>::run(o_);
          o_ << ", ";
          mpllibs::error::to_stream_impl<position>::run(o_);
          return o_ << ">";
        }
      };
    };
  }
}

#endif

