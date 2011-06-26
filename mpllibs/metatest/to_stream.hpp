#ifndef MPLLIBS_METATEST_TO_STREAM_HPP
#define MPLLIBS_METATEST_TO_STREAM_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/tag.hpp>

namespace mpllibs
{
  namespace metatest
  {
    template <class T>
    struct to_stream_impl
    {
      template <class V>
      struct apply
      {
        typedef apply type;
      
        static std::ostream& run(std::ostream& o_)
        {
          // I can't use typeid, because it breaks for non-defined types
          return o_ << "???";
        }
      };
    };
    
    template <class T>
    struct to_stream :
      boost::mpl::apply_wrap1<
        to_stream_impl<typename boost::mpl::tag<T>::type>,
        T
      >
    {};
    
    template <class T>
    struct to_stream<T*>
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return to_stream<T>::run(o_) << "*";
      }
    };

    template <class T>
    struct to_stream<T[]>
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return to_stream<T>::run(o_) << "[]";
      }
    };

    template <class T>
    struct to_stream<T&>
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return to_stream<T>::run(o_) << "&";
      }
    };

    template <class T>
    struct to_stream<const T>
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return to_stream<T>::run(o_ << "const ");
      }
    };

    template <class T>
    struct to_stream<T* const>
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return to_stream<T>::run(o_) << "* const";
      }
    };
  }
}    

#ifndef MPLLIBS_NO_TO_STREAM_MPL
#include <mpllibs/metatest/to_stream_mpl.hpp>
#endif

#endif

