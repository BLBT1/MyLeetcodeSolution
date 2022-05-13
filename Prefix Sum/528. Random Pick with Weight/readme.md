# 528. Random Pick with Weight

- presum 来表达 cdf，每个 presum 就是每个数对应的数字区间的最后一个

- r = rand()% presum.back + 1

- 用二分搜索找到 idx >= r
