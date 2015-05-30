```cpp
template <class S, class Item> struct binary_op : eval_binary_op< S, boost::mpl::at_c<Item, 0>::type::value, typename boost::mpl::at_c<Item, 1>::type > {};

```
