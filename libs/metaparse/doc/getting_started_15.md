```cpp
using exp_parser12 = build_parser< foldlp< sequence<one_of<plus_token, minus_token>, int_token>, int_token, boost::mpl::quote2<sum_items> > >;

```
