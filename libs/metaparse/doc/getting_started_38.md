```cpp
#include <mpllibs/metaparse/foldlfp.hpp>
struct plus_exp5 : foldlfp< sequence<one_of<plus_token, minus_token>, mult_exp6>, mult_exp6, boost::mpl::quote2<binary_op> > {};
using exp_parser22 = build_parser<plus_exp5>;

```
