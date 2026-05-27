```c++
class Solution {
    unordered_map<char, vector<char>> num2Letters = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    vector<string> res;
public:
    vector<string> letterCombinations(string digits) {
        dfs(digits, -1, "");
        return res;
    }

    void dfs(string digits, int currIdx, string currStr){
        if(currIdx == digits.size()-1){
            res.push_back(currStr);
            return;
        }
            
        int nxtIdx = currIdx+1;
        for(auto c : num2Letters[digits[nxtIdx]]){
            currStr.push_back(c);
            dfs(digits, nxtIdx, currStr);
            currStr.pop_back();
        }
    }
};
```