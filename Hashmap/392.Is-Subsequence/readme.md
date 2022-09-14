# 392. Is Subsequence

这个题的双指针是很好写的，问题是follow up， 假设有很多个s，[s1...si...sk], 那该怎么做。

- 可以同 map 记录所有每个字母在 t 中出现的位置

- 用 pos 代表下一个 t 中搜索的位置是 (pos, t.end()]

- 建立pos的初始位置-1. 然后遍历s[i]：在Map[s[i]]里找第一个大于pos的位置并更新pos，则之后对于s[i+1]的查找必须从t的新pos位置开始 (guan 神)
