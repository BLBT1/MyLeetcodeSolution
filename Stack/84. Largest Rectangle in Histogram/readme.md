# 84. Largest Rectangle in Histogram

- 栈保持单调递增，因为只有 i 小于 s.top() 的时候才可能是 以 i 为右边界 exclusive 的 最大长方形

- 左边界是 s 中 第二的位置， 或者是-1； 高是 s.top() 的高度

- 当 indx 走完， stack 还会存几个， 用 right = heights.size()
