class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // find the last position of increasing array
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l + 1) / 2;
            if (mid == 0 || nums[mid] > nums[0])
                l = mid;
            else
                r = mid - 1;
        }
        if (l != nums.size() - 1)
            return nums[l + 1];
        else
            return nums[0];
    }
};
// another solution:
// compare mid and left + find first pos of rotated
// if(nums[l] < nums[r])
//     return nums[l];
// else if (nums[mid] >= nums[l])
// {
//     l = mid + 1;
// }
// else
// {
//     r = mid;
// }
