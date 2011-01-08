#ifndef MPLLIBS_ERROR_EXCEPTION_H
#define MPLLIBS_ERROR_EXCEPTION_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

namespace mpllibs
{
  namespace error
  {
    struct Exception_tag;
  
    template <class Data, class Location>
    struct Exception
    {
      typedef Exception_tag tag;
      typedef mpllibs::error::Exception<Data, Location> type;
    };
    
    template <class>
    struct get_data_impl;
    
    template <>
    struct get_data_impl<Exception_tag>
    {
      template <class>
      struct apply;
      
      template <class Data, class Location>
      struct apply<Exception<Data, Location> >
      {
        typedef Data type;
      };
    };


    template <class>
    struct get_location_impl;
    
    template <>
    struct get_location_impl<Exception_tag>
    {
      template <class>
      struct apply;
      
      template <class Data, class Location>
      struct apply<Exception<Data, Location> >
      {
        typedef Location type;
      };
    };
  }
}

#endif

