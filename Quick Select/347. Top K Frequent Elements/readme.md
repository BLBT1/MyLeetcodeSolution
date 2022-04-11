# 347. Top K Frequent Elements

- 最优是用quick select

- 随机找一个pivot， 然后把比pivot 大的放一边，比pivot小的放一边，用lc75 三色排序的算法可以O(n)完成这一步

- 三色排序结束后arr如下

```cpp
// [S SSS PPP GGGGG]
//  B     i j t   End
```

- 大于pivot的数字 (End-j) >= k，只需要在 Greater 的部分做 quick Select

- 如果大于等于 pviot的数字 （end-i+1） >= k,且(End-j) < k, 那 pivot就是我们的目标， return即可

- 剩下的情况，大于等于 pviot的数字 小于 k，那 需要在 小于pivot的数字 找 k-大于等于pviot的数字的个数， 即找第（k-（end-i+1））

- 把这三种情况写成代码就是

```cpp
        if (rightSize>=k) 
            return quickSelect(arr, k, j+1, end);
        else if (end-i+1>=k) 
            return p;
        else 
            return quickSelect(arr, k-(end-i+1), begin, i-1);
```
