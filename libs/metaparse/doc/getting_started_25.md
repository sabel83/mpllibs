```cpp
using mult_exp3 = foldrp< sequence<int_token, one_of<times_token, divides_token>>, /* The parser applied repeatedly */ int_token, /* The parser parsing the last number */ boost::mpl::quote2<reverse_binary_op> /* The function called for every result */ /* of applying the above parser */ >;

```
