/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        const int n = strs.size();
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < n; ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            map[s].push_back(strs[i]);
        } //for

        //key,val pair
        for (auto list : map)
        {
            res.push_back(list.second);
        }
        return res;
    }
};
// @lc code=end
