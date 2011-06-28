#ifndef MPLLIBS_METAMONAD_RETURN__HPP
#define MPLLIBS_METAMONAD_RETURN__HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <mpllibs/metamonad/throw.hpp>
#include <mpllibs/metamonad/meta_atom.hpp>
#include <mpllibs/metamonad/overloading_error.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/tag.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_DEFINE_META_ATOM(overloading_error_tag, return_not_defined);

    template <class>
    struct return__impl : MPLLIBS_THROW<return_not_defined> {};
    
    struct no_return_argument;

    template <class MonadTag, class A = no_return_argument>
    struct return_ : boost::mpl::apply_wrap1<return_<MonadTag>, A>
    {
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "return_<";
          mpllibs::metatest::to_stream_argument_list<MonadTag, A>::run(o);
          return o << ">";
        }
      };
    };
    
    template <class MonadTag>
    struct return_<MonadTag, no_return_argument>
    {
      typedef return_ type;
      
      template <class A>
      struct apply : boost::mpl::apply_wrap1<return__impl<MonadTag>, A> {};
      
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "return_<";
          mpllibs::metatest::to_stream_argument_list<MonadTag>::run(o);
          return o << ">";
        }
      };
    };
  }
}

#endif

