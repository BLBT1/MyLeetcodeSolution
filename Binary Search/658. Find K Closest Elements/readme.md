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
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       // search for L in idea2, such that L is samllest that k away from x
       int l = 0;
       int r =  arr.size()-k; // if k == arr.size(), r is alreay 0, so we can exit while loop

        while(l < r) {
            int mid = l+(r-l)/2;
            // we are searching the L (samllest number in res, so L+k is k+1 number closest from x)
            if (x-arr[mid] <= arr[mid+k]-x) {
                // right of R cannot not be k+1 closest
                // R can be still k+1 as if x-L==R-x, we take L into res.
                r = mid;
            } else {
                // because if L is k+1 away, it should not be in res, so mid+1
                l = mid+1;
            }
        }

        vector<int> res;
        for(int i=l; i < l+k; ++i)
            res.push_back(arr[i]);

        return res;
    }
};

// Input: arr = [1,2,3,4,5], k = 4, x = 3
// idea1: find target x index, then use 2 ptr (logN+K)
//
// idea2:
// binary search 的本质是要找到什么搜索区间可以被排除
// 这道题里 因为是找到k closest的区间， 所以从第k+1 closest的数字都可排除
// XXXX L______R XXXX
//.         x
// 我们可以假设 L是k+1 closest from k
// if L 是 k+1 away from x，那包括 XXXL 都可以排除
```