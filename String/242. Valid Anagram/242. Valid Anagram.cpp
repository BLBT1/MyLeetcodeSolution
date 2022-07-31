class Solution
{
    int arr[26];

public:
    bool isAnagram(string s, string t)
    {
        for (auto c : s)
            arr[c - 'a']++;
        for (auto c : t)
        {
            arr[c - 'a']--;
            if (arr[c - 'a'] < 0)
                return false;
        }
        for (auto i : arr)
        {
            if (i > 0)
                return false;
        }
        return true;
    }
};