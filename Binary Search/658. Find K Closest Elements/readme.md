# 658. Find K Closest Elements

## 解题思路

1. 这题其实是要在arr里找一个大小为k的window，中间的数字的值是最close to x 的k个数字。所以说，我们的突破口可以从寻找这个window的左端点开始
2. 此题的另一个突破口是， 可以每次检查一个 ```k+1``` 大小的window，这样此window中必然有一个是 invalid 的 element。（这个想法惊为天人）
3. 所以我们搜索的上下界（window的左端点）在 [0, arr.size()-k] 之间， 定为 low 和 hi

4. 看mid point 的值是 靠近 low 多还是 hi 多
    - 如果靠近 hi 多， 那  [low:mid] 中的点都不可能是 valid 的 window的左端点
    - 如果靠近 low 多， 那 (mid:hi] 中的点都不是 valid 的 window的左端点
    - 如果一样多，那按照要求， 和如果靠近 low 多是一样的

```cpp
        if (x - arr[mid] > arr[mid + k] - x)
        {
            // this case the left end of window is not a valid left end
            lo = mid + 1;
        }
        else if (x - arr[mid] < arr[mid + k] - x)
        {
            // this case the right end is not a valid end,
            // so the curr mid is not valid left end
            // as the window size is k+1
            // we can just set hi to mid
            hi = mid;
        }
        else
        {
            // if eq
            // then by the problem
            // same as the right end is not valid
            hi = mid;
        }
```

5. 为啥比较的时候没有取abs？ans: lee原本的post里有提到这个问题，简单来说，如果取绝对值，则在arr[mid]和arr[mid+k]相同时，无法区分 x<arr[mid] 与 x>arr[mid+k] 的情况。取abs失去了方向信息。具体的例子可以看 [寒神贴](https://leetcode.com/problems/find-k-closest-elements/discuss/106426/JavaC%2B%2BPython-Binary-Search-O(log(N-K)-%2B-K)) 里的说明
