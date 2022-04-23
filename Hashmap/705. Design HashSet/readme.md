# 705. Design HashSet

- 使用chaining， vector of linked list

- 注意， std::vector 和 std::list 在c++里没有 find

- 所以我们要用 std::Iterator 里的的find， 返回的是一个指向相关node的iterator
