class Solution {
    public int minimumAverageDifference(int[] nums) 
    {    
        long[] presum = new long[nums.length];
        long[] postsum = new long[nums.length];
        long sum = 0;
        long sumPost = 0;
        for(int i = 0; i < nums.length; ++i)
        {
            sum += nums[i];
            presum[i] = sum;
            postsum[nums.length-1-i] = sumPost;
            sumPost += nums[nums.length-1-i];
        }
        
        long currMin = Long.MAX_VALUE;
        int res = 0;
        for(int i = 0; i < nums.length; ++i)
        {
            long preAvg = (long)(presum[i]/(i+1));
            long x = nums.length-i-1;
            long postAvg = (x == 0)? 0:(int)(postsum[i]/x);
            long diff = Math.abs(preAvg - postAvg);
            if (diff < currMin)
            {
                currMin = diff;
                res = i;
            }
        }
        return res;
    }
}

// [2, 5, 3, 9, 5, 3]
//  2  7  10 19 24 27