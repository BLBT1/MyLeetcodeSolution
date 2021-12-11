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
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    //convert problem from exact k to at most k
    int atMostK(vector<int> &nums, int k)
    {
        const int n = nums.size();
        unordered_map<int, int> map; //{val, # of appearance in the window}
        int i = 0;
        int j = 0;
        int cnt = 0;
        // j 正常移动
        // i 伺机而动
        for (; j < n; j++)
        {
            map[nums[j]]++;
            while (map.size() > k)
            {
                map[nums[i]]--;
                if (map[nums[i]] == 0)
                    map.erase(nums[i]);
                ++i;
            }
            // num of valid substring is
            // set a fix j for the right(exclusive)
            // and i, i+1, i+2 ..., j all valid left side
            cnt += j - i + 1;
        } //for
        return cnt;
    }
};
// @lc code=end

//nums = [1,2,1,2,3], k = 2
//        i
//        j
// hashmap {num, #apperance in the window}
//{1, 1}
//{2, 1}
//distinct  = # of element
//cnt = 1
// if distinct <= k
//      if distinct == k
//          cnt++
// if distinct > k;
//  --hashmap[i],
//  if hashmap[i] == 0
//        --distinct
//  ++i