class Solution
{
    unordered_map<char, string> mp;
    vector<string> res;
    string list;

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        dfs(digits, 0);
        return res;
    }

    void dfs(string digit, int curr)
    {
        if (curr == digit.size())
        {
            res.push_back(list);
            return;
        }

        for (auto c : mp[digit[curr]])
        {
            list.push_back(c);
            dfs(digit, curr + 1);
            list.pop_back();
        }
    }
};