```cpp
using exp_parser14 = build_parser< foldlp< sequence<one_of<plus_token, minus_token, times_token>, int_token>, int_token, boost::mpl::quote2<binary_op> > >;

```
