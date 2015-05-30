```cpp
struct plus_exp2 : foldlp< sequence<one_of<plus_token, minus_token>, mult_exp5>, mult_exp5, boost::mpl::quote2<binary_op> > {};

```
