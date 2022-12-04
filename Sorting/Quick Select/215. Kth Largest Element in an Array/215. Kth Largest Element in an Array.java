class Solution {
    public int findKthLargest(int[] nums, int k) 
    {    
        int res = quickSelect(nums, 0, nums.length-1, k);
        return res;
    }
    
    private int quickSelect(int[] nums, int begin, int end, int k)
    {
        int pivot = nums[begin];
        int i = begin;
        int j = end;
        int w = begin;
        while(w <=j)
        {
            if(nums[w] < pivot)
            {
                swap(nums, i, w);
                ++i;
                ++w;
            }
            else if(nums[w] > pivot)
            {
                swap(nums, j, w);
                --j;
            }
            else
            {
                ++w;
            }
        }
        
        if(end-j>=k)
            return quickSelect(nums, j+1, end, k);
        else if(end-i+1 >= k)
            return pivot;
        else
            return quickSelect(nums, begin, i-1, k-(end-i+1));
    }
    
    private void swap(int[] nums, int i, int j){
        var temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

// SSSPPPLLLL
// b  i j   e