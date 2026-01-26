```c++
class Solution {
    static bool comp(string &s1, string &s2){
        if(s1.size()!=s2.size()){
            return s1.size()>s2.size();
        }
        return s1<s2;
    }
public:
    string findLongestWord(string s, vector<string>& dict) {
        sort(dict.begin(), dict.end(), comp);

        for (auto &d: dict) {
            int i = 0;
            int j = 0;

            while (i < s.size() && j < d.size()) {
                if(s[i] == d[j]) {
                    ++i;
                    ++j;
                } else {
                    ++i;
                }
            }

            if (j == d.size()) // anything at the end of s can be deleted
                return d;
        }
        return "";
    }
};

// 1. sort dict
// ["monkey", "apple", "plea", "ale"]
// 2. compare each s with word in dict
// DlogD + D(N+M), D is length of dict, N is length for s, M is longest word in dict

// abpcplea
        //  i    
// apple
    //    j
```