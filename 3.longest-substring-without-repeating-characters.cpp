/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //* idea: 移动右边指针，并且在 o(1) 时间快速判断出左边指针的位置
        unordered_map<int, int> Map; // record the pos of each char's last appear
        int i = 0;
        int result = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (Map.find(s[j]) != Map.end())
                i = max(i, Map[s[j]] + 1);
            Map[s[j]] = j;
            result = max(result, j - i + 1);
        }
        return result;
    }
};
// @lc code=end
