```cpp
struct plus_exp6;
using paren_exp5 = middle_of<lparen_token, plus_exp6, rparen_token>;
using primary_exp4 = one_of<int_token, paren_exp5, fail<missing_primary_expression>>;
using unary_exp4 = foldrp< minus_token, primary_exp4, boost::mpl::lambda<boost::mpl::negate<boost::mpl::_1>>::type >;
using mult_exp7 = foldlfp< sequence<one_of<times_token, divides_token>, unary_exp4>, unary_exp4, boost::mpl::quote2<binary_op> >;
struct plus_exp6 : foldlfp< sequence<one_of<plus_token, minus_token>, mult_exp7>, mult_exp7, boost::mpl::quote2<binary_op> > {};
using exp_parser23 = build_parser<plus_exp6>;

```
