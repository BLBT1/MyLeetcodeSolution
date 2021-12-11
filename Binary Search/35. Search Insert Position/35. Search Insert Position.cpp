class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size();
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
        return r;
    }
};