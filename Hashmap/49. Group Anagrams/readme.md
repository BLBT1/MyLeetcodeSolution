# 49. Group Anagrams

- 用每个string 排序过的结果作为key，就能group by anagram了

- 做到anagram的题 都可以想想要不要排序

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> sortedString; // list of sorted string to list
        
        // O(N*L*log(L)) -> N is number of words, L is length of words
        for (auto s: strs){
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            sortedString[sorted].push_back(s);
        }

        vector<vector<string>> res;
        for(auto p: sortedString){
            res.push_back(p.second);
        }

        return res;
    }
};
```