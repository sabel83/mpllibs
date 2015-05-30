```cpp
using mult_exp4 = foldlp< sequence<one_of<times_token, divides_token>, unary_exp1>, unary_exp1, boost::mpl::quote2<binary_op> >;
using exp_parser18 = build_parser< foldlp< sequence<one_of<plus_token, minus_token>, mult_exp4>, mult_exp4, boost::mpl::quote2<binary_op> > >;

```
