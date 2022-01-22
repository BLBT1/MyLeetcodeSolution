# 875. Koko Eating Bananas

这个题目第一反应肯定会往dp或greedy方向想，但是很意外啊，这个题是一个另类且经典的 ```binary search```。 我女朋友面试就遇到了这个原题，她十分懵逼

### 核心思想： 猜答案
我们先看一个例子：
```
                 0  1  2  3
Input: piles = [ 3, 6, 7, 11], h = 8
Output: 4
```
为什么答案是4？
```
hr 0: piles[0] all 全吃了
hr 1: piles[1] 吃了4个，剩余2个
hr 2: piles[1] 吃完
hr 3: piles[2] 吃了4个，剩余3个
hr 4: piles[2] 吃完
hr 5: piles[3] 吃了4个， 剩余11-4 = 7个
hr 6: piles[3] 吃了4个，剩余 7-4 = 3个
hr 7: piles[3] 吃完
hr 8: 吃完
```
我们发现一个规律：
- 如果 piles[i] 的个数有 n 个， 则需要 n/k+1 hr 吃完：
    - 比如 piles[3], 需要 11/3+1 = 4 hr吃完
    - 比如 piles[1], 需要 6/4 = 2 hr 吃完
- 有一个特殊情况：如果piles[i]%k == 0,  则只需 n/k hr 吃完
    - 比如 piles[i] = 1, k = 1, 则需 1 hr吃完这个pile
- 我们可以把所有piles所需的时间相加， 看看是不是 <= h


以此规律，我们能先写出一个判断一个 given k 是否能全吃完的function：
```cpp
    bool canFinish(vector<int> &piles, int h, int k)
    {
        int sum = 0;
        for (int i = 0; i < piles.size(); ++i)
        {
            if (piles[i] % k == 0)
                sum += piles[i] / k;
            else
                sum += (piles[i] / k + 1);
        }
        return sum <= h;
    }
```
此题剩余部分就是确定上下界，然后聪明的去```猜答案```

- 上界： 如果每次都吃 ```最大pile的个数```，则肯定是少用时，及 piles 的个数
- 下界： 至少得吃一个，每次
- 所以我们无非就是在 [1:最大pile的个数] 中猜一个数，再用我们上面的方法去试验此数是否能吃完，直到试验到最小且能吃完的那个数字
- 那怎么最快试验出结果呢？ 用```用二分搜索```