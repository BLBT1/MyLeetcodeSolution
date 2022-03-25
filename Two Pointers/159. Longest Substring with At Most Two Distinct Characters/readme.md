# 159. Longest Substring with At Most Two Distinct Characters

- 是 lc1146 和 lc3 的一个变化

- 需要用 unordered_map 记录更新每个char最后出现的位置

- 如果 map 里的 char 超过2个了， 那我们需要 traverse map找到最后出现位置最左的一个，把他删了，且把 i 移到那个最左的位置+1的地方
