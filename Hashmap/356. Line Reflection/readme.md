# 356. Line Reflection

这个题首先是要理解题意， 给了一系列点， 需要判断是不是所有点都能按照 一条 平行与 y 轴的点对称。

需要想到的是， 如果所有点都要对称与一条竖线， 那 最左边和最优边的点一定是 对称与竖线的， 我们可以通他们找到竖线的 x轴 位置， 同时把所有点存进一个set，serialize一下。这样就可以在hashset里快熟查找是不是每一个点都在里面了