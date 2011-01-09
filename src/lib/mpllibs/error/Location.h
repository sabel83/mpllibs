#ifndef MPLLIBS_ERROR_LOCATION_H
#define MPLLIBS_ERROR_LOCATION_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

namespace mpllibs
{
  namespace error
  {
    struct Location_tag;
  
    template <class File, class Line>
    struct Location
    {
      typedef Location_tag tag;
      typedef mpllibs::error::Location<File, Line> type;
    };
    
    
    template <class>
    struct get_file_impl;
    
    template <>
    struct get_file_impl<Location_tag>
    {
      template <class>
      struct apply;
      
      template <class File, class Line>
      struct apply<Location<File, Line> >
      {
        typedef File type;
      };
    };



    template <class>
    struct get_line_impl;
    
    template <>
    struct get_line_impl<Location_tag>
    {
      template <class>
      struct apply;
      
      template <class File, class Line>
      struct apply<Location<File, Line> >
      {
        typedef Line type;
      };
    };
  }
}

#endif

