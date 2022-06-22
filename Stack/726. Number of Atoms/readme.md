# 726. Number of Atoms

- 这个题最精妙的地方就是 stack<map<string, int>> 这个数据结构， 因为我们最后关心的是elt的排序和出现的次数。 用 两个stack也能做，但是需要最后再处理， 十分麻烦
