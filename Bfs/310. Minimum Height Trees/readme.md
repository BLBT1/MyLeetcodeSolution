# 310. Minimum Height Trees

想要最矮的树的顶点，关键是要从中间的点开始拿。 那中间的点有什么特征呢？他们的 degree 肯定是最大的。想到这里就可以用拓扑排序了。一直从 degree 为 1 的点往里剥洋葱，最后剩下的一两个点就是我们要的答案