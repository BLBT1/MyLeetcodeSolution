/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */
#include <iostream>
#include <string>
#include <sstream> // std::istringstream
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseWords(string &s)
    {
        if (!s.size())
            return "";
        istringstream ss(s);
        string word;
        string res;
        while (ss >> word)
        {
            if (res.empty())
            {
                res = word;
            }
            else
            {
                res = word + " " + res;
            }
        }
        return res;
    }
};
// @lc code=end
