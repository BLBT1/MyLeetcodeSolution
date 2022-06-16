class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2)
    {
        // use a stack to find NGE for all elts in nums2
        Stack<Integer> stack = new Stack<>();
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i = nums2.length-1; i >= 0; --i)
        {
            while(!stack.isEmpty() && nums2[i]>= stack.peek())
                stack.pop();

            if(stack.empty())
                mp.put(nums2[i], -1);
            else
                mp.put(nums2[i], stack.peek());
            stack.push(nums2[i]);
        }

        for(int i = 0; i < nums1.length; ++i)
            nums1[i] = mp.get(nums1[i]);

        return nums1;
    }
}

// find Next Greater => non-increasing
// find next smaller => non-decreasing
// nums2: [1,3,-1, -1]
// stack: 4, 3
//

