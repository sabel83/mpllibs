```cpp
using exp_parser15 = build_parser< foldlp< sequence<one_of<plus_token, minus_token>, mult_exp1>, mult_exp1, boost::mpl::quote2<binary_op> > >;

```
