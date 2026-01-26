# 75. Sort Colors

涵盖这个题在在sorting里， 因为这个方法在quick select 里很常用

- i -> one idx after 0 pile
- j -> one idx before 2 pile
- k -> the unknown element we are examining

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0; 
        int j = nums.size()-1;
        int k = 0;

        while(k <= j) {
            if (nums[k] == 0) {
                swap(nums[k], nums[i]);
                k++;
                i++;
            } else if (nums[k] == 1) {
                k++;
            } else {
                swap(nums[k], nums[j]);
                --j;
            }
        }
    }
};


// [2,0,2,1,1,0] 
// 
//

//            k
// 0000 011111X 222
//       i. 
//            j 
// i -> one idx after last 0
// k -> curr comparing
// j -> last for 1

// if nums[k] == 0
//     k++, i++
// if nums[k] == 1
//     k++
// if nums[k] == 2
//.     swap(nums[k], nums[j])
//     --j

//.   k.  
// [1,,2]
//  i
//.   j

//.   k
// [1,0,2]
//. i
//.   j
```
