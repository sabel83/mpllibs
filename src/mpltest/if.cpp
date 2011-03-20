#include <mpllibs/metatest/test.h>

#include <boost/mpl/if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite ("if");

  namespace mpl = boost::mpl;

  typedef
    mpl::equal_to <
        mpl::if_ <
            mpl::true_
          , mpl::int_ <1>
          , mpl::int_ <2>
        > ::type
      , mpl::int_ <1>
      > ifTrue;

  typedef
    mpl::equal_to <
        mpl::if_c <
            true
          , mpl::int_ <1>
          , mpl::int_ <2>
        > ::type
      , mpl::int_ <1>
      > ifcTrue;

  typedef
    mpl::equal_to <
        mpl::if_ <
            mpl::false_
          , mpl::int_ <1>
          , mpl::int_ <2>
        > ::type
      , mpl::int_ <2>
      > ifFalse;

  typedef
    mpl::equal_to <
        mpl::if_c <
            false
          , mpl::int_ <1>
          , mpl::int_ <2>
        > ::type
      , mpl::int_ <2>
      > ifcFalse;
}

MPLLIBS_ADD_TEST (suite, ifTrue)
MPLLIBS_ADD_TEST (suite, ifcTrue)
MPLLIBS_ADD_TEST (suite, ifFalse)
MPLLIBS_ADD_TEST (suite, ifcFalse)

