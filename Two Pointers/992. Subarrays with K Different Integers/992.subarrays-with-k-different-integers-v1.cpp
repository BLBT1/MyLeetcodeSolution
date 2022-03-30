/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        // num of good string with exact k different int
        // = num of good string with <= k different in
        // - num of good string with <= k-1 different in
        return subarrayWithMostKDistinct(nums, k) - subarrayWithMostKDistinct(nums, k - 1);
    }

    int subarrayWithMostKDistinct(vector<int> &nums, int k)
    {
        int l = 0, r = 0;
        int res = 0;
        unordered_map<int, int> Map;
        if (k == 0)
            return 0;
        for (; r < nums.size(); ++r)
        {
            if (Map.find(nums[r]) != Map.end() || Map.size() < k)
            {
                Map[nums[r]] = r;
            }
            else
            {
                int leftMost;
                int pos = nums.size();
                for (auto &p : Map)
                {
                    if (p.second < pos)
                    {
                        pos = p.second;
                        leftMost = p.first;
                    }
                }
                // remove the leftMost and add in the newchar
                // res += pos-l;
                l = pos + 1;
                Map.erase(leftMost);
                Map[nums[r]] = r;
            }
            res += r - l + 1;
        }
        return res;
    }
};
}
;
// @lc code=end

// nums = [1,2,1,2,3], k = 2
//         i
//         j
//  hashmap {num, #apperance in the window}
//{1, 1}
//{2, 1}
// distinct  = # of element
// cnt = 1
//  if distinct <= k
//       if distinct == k
//           cnt++
//  if distinct > k;
//   --hashmap[i],
//   if hashmap[i] == 0
//         --distinct
//   ++i