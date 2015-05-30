```cpp
#include <boost/mpl/negate.hpp>
using unary_exp1 = foldrp< minus_token, int_token, boost::mpl::lambda<boost::mpl::negate<boost::mpl::_1>>::type >;

```
