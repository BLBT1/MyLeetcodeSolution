class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == nums[mid + 1])
            {
                if (mid % 2 == 0)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            else
            {
                if (mid % 2 == 0)
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return nums[left];
    }
};