// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MY_REVERSE_H_INCLUDED
#define MY_REVERSE_H_INCLUDED

#include "my_reverse_fwd.h"
#include "my_reverse_impl.h"

#include <boost/mpl/sequence_tag.hpp>

template< typename Sequence >
struct my_reverse
  : my_reverse_impl<
          typename boost::mpl::sequence_tag<Sequence>::type
      >::template apply<Sequence>
{};

#endif // MY_REVERSE_H_INCLUDED
