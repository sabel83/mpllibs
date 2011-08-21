#ifndef MPLLIBS_METAMONAD_MONOID_HPP
#define MPLLIBS_METAMONAD_MONOID_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/typeclass.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/reverse_fold.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metamonad
  {
    template <class Tag>
    struct monoid
    {
      MPLLIBS_TYPECLASS_EXPECT(empty)
      MPLLIBS_TYPECLASS_EXPECT(append)
      MPLLIBS_TYPECLASS_EXPECT(concat)
    };
    
    template <class Tag>
    struct monoid_defaults : monoid<typeclass_expectations>
    {
      struct concat
      {
        typedef concat type;
      
        template <class L>
        struct apply :
          boost::mpl::reverse_fold<
            L,
            typename monoid<Tag>::empty,
            typename monoid<Tag>::append
          >
        {};
        
        struct to_stream
        {
          static std::ostream& run(std::ostream& o_)
          {
            o_ << "monoid<";
            mpllibs::metatest::to_stream<Tag>::run(o_);
            return o_ << ">::concat";
          }
        };
      };
    };
  }
  
  namespace metatest
  {
    template <class Tag>
    struct to_stream<mpllibs::metamonad::monoid<Tag> >
    {
      static std::ostream& run(std::ostream& o_)
      {
        o_ << "monoid<";
        mpllibs::metatest::to_stream<Tag>::run(o_);
        return o_ << ">";
      }
    };
  }
}

#endif

