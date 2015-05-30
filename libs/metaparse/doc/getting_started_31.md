```cpp
using plus_exp1 = foldlp< sequence<one_of<plus_token, minus_token>, mult_exp4>, mult_exp4, boost::mpl::quote2<binary_op> >;

```
