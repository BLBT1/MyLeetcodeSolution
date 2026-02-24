```c++
class Solution {
public:
    int minSteps(string s, string t) {
        int count1[26];
        int count2[26];

        int i = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i){
            count1[s[i]-'a'] +=1;
            count2[t[i]-'a'] +=1;
        }

        int diff = 0;
        for(int i =0; i < 26; ++i){
            diff += abs(count1[i]-count2[i]);
        }
        return diff/2;
    }
};

// diff [1,2,3,4,1,2,3,4 ...]
```