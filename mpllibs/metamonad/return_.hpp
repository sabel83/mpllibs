#ifndef MPLLIBS_METAMONAD_RETURN__HPP
#define MPLLIBS_METAMONAD_RETURN__HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <mpllibs/metamonad/monad.hpp>

#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class MonadTag, class T>
    struct return_ :
      boost::mpl::apply_wrap1<
        typename mpllibs::metamonad::monad<MonadTag>::return_,
        T
      >
    {
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "return_<";
          mpllibs::metatest::to_stream_argument_list<MonadTag, T>::run(o);
          return o << ">";
        }
      };
    };
  }
}

#endif

