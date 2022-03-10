# 702. Search in a Sorted Array of Unknown Size

- 经典的二分搜索，如何确定搜索上界？　看　requirement 里的upper bound.

- 如果　out off bound, 那会返回　INT_MAX，也不可能，所以右侧也要收缩
