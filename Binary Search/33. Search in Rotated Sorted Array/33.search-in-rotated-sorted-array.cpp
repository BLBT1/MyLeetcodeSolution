class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[l])
            {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid;
            }
            else
            {
                if (nums[mid] >= target && target >= nums[l])
                    r = mid;
                else
                    l = mid + 1;
            }
        }
        if (nums[l] == target)
            return l;
        return -1;
    }
};