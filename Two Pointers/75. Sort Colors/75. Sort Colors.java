class Solution {
    
    private void swap(int[] a, int i, int j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    
    public void sortColors(int[] nums) 
    {
        int i = 0;
        int k = 0;
        int j = nums.length-1;        
        
        while(k <= j)
        {
            if(nums[k] == 0)
            {
                swap(nums,i, k);
                ++k;
                ++i;
            }
            else if(nums[k] == 1)
            {
                ++k;
            }
            else if(nums[k] == 2)
            {        
                swap(nums, j, k);
                --j;
            }
        }
    }
}

// i -> first after 0
// k -> examining
// j -> last element before 2 
// 00000111XXX2222
//      i k
//          j
// if nums[k] == 0
//    swap(i, k)
//     ++k;
//     ++i;
// if nums[k] == 1
//     ++k
// if nums[k] == 2
//      swap(k, j)
//      --j;
//      