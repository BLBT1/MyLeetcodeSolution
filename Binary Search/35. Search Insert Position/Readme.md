# 35. Search Insert Position

此题是binary search的模板题，很基础，初学者一定要牢记于心，闭着眼睛也要能默写出来
```cpp
        int l = 0, r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2; // [0,1] -> 0
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else if (nums[mid] > target)
            {
                r = mid;
            }
            else
            {
                return mid;
            }
        }
```