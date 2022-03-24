# 1901. Find a Peak Element II

- 二维的二分搜索， 但是又没有每行每列排序， 所以我们思路是每一行找到一个代表（每行最大）进行二分搜索。m*n 的 matrix中，我们设搜索的范围为是所有的行：[lower, upper] =  [0:m-1] 行。找到 mid = (upper-lower)/2+lower

- 分别找到 mid_max, upper_max, lower_max, 如果 mid_max 是三个最大，那么 已知 mid_max 是本行最大，而且 mid_max >= upper_max >= upper_neighbor, 同理 mid_max >= lower_max >= lower_neighbor, 因此 mid_max 一定是 peak element， 返回当前位置

- 如果 upper_max 是三个中最大， 那 和一维的 peak element 一样的思路，我们把搜索区间变成 [mid+1, upper], 因为mid中没找到peak element，且 [low ：mid] 中都不会有

- 同理， 如果lower_max 最大，我们把搜索区间变成 [lower, mid-1]

- 需要注意， 当 upper 和 lower 收敛， 也就是 upper == lower 时， 我们还不能停止搜索，以下example就是一个证明:

```
    [[10,20,15],
    [21,30,14],
    [7,16,32]]
```
