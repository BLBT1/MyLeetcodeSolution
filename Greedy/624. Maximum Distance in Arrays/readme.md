# 624. Maximum Distance in Arrays

此题的贪心思想是，最大的差一定是每个array的头尾相减。我们就需要找最大的尾减去除自己外最小的头。但是如果我们直接找到他们是错的，比如这个例子

[[-2], [-3, 1]]

先找最小的头是 -3， 那最大的尾巴只剩下-2，dist是1， 这是错的

所以顺序是重要的，如果先找最大的尾巴， 那 [[1,5],[3,4]] 这个例子就有问题了

所以我们要对比所有最大的尾巴和最小的头的差

```cpp

    int curr = max(abs(arrays[i].back()-left), abs(arrays[i].front()-right));
    res = max(res, curr);
    left = min(left, arrays[i].front());
    right = max(right, arrays[i].back());

```
