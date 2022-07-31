# 46. Permutations

- permutation 可以确定的是list的长度肯定要是 nums 的长度， 所以这是 base case

- 此外，每个数字都要出现在任何位置， 所以 dfs 中 的 for loop 要从 0 开始

- 每个数字在list中只能出现一次， 所以要用个 set来记录是不是有用过当前的数字

- time: O(N!), space: O(N)
