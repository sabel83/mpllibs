```cpp
using exp_parser17 = build_parser< foldlp< sequence<one_of<plus_token, minus_token>, mult_exp3>, mult_exp3, boost::mpl::quote2<binary_op> > >;

```
