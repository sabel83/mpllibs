#ifndef MPLLIBS_METAPARSE_RETURN_HPP
#define MPLLIBS_METAPARSE_RETURN_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/get_remaining.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_position.hpp>

#include <mpllibs/metamonad/tmp_tag.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    struct accept_tag : mpllibs::metamonad::tmp_tag<accept_tag> {};
    
    template <class C>
    struct return_
    {
      typedef return_ type;
      
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
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  mpllibs::metaparse::return_,
  "metaparse::return_"
)

#endif

