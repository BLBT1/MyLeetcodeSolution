# 366. Find Leaves of Binary Tree

需要熟悉的一个定义是： 树的height 就是当前点到当前点以下最深的leave的距离，此题其实是 group 相同 height的点在一起。所以 res[i] 就是所有height 为 i 的点。 这样我们可以用 postOrder 找到每个点的height，同时把他放进相应高度的 group。 我感觉还是很巧妙的
