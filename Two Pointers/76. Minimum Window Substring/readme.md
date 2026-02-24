# 76. Minimum Window Substring

the hard part of this problem is 
1. The only window that is valid (containing all of t), must has both begin and end with letter in t
2. if t contains duplicates say "aa", valid window must contain same number of "aa"
     -> so we need to have a map to count how many appears for each letters from t
3. How do we fastly know if all t letter are in the window?
     -> keep a map to count the appears for the chars that in t, 
     -> a counter count to record **how many letter has the same number of letter in window vs. t map**
4. *when we find a valid window, it is possible that the window could have more number than we required
     example, if t = "aab", s = "xyz[aaaaaab]", for the window, we finally get the b, but # of a is way more then required
     so we need to have a while loop to move left util map['a'] < t_map['a']

// 有指针正常移 （进map）， 左指针伺机而动 （退元素出map），当window valid的时候计算

- 这个题还用了一个 cnt 和 M 的技巧来判断 Map 是不是满足 Table的要求，用 cnt记录所有满足标准的char的个数， 如果满足要求的char的个数cnt == 所有有要求的char的个数，那sub string s[l:r]就满足要求。这个技巧很有用， lc395里也用了

```c++
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_map; // count # of appear for chars in t
        for (auto &c: t) t_map[c]++;
        int numUnique = t_map.size();
        
        unordered_map<char, int> s_map; // all chars in curr window
        int l = 0;
        int count = 0; // num of unique chars that s_map has satisfied t_map

        int curr_min = INT_MAX;
        int res_begin = 0;
        int res_end = 0;
        bool found = false;
        for (int i =0; i < s.size(); ++i){
            s_map[s[i]]++;
            
            if (s_map[s[i]] == t_map[s[i]]){
                count += 1;
            }

            if(count == numUnique) {
                found = true;
                // calculate results
                if (i-l+1 < curr_min) {
                    // we have new result
                    res_begin = l;
                    res_end = i;
                    curr_min = i-l+1;
                }
                // move left point for new valid window
                while(l <= i && count == numUnique) {
                    // window is still good, so calculate res
                    if (i-l+1 < curr_min) {
                        // we have new result
                        res_begin = l;
                        res_end = i;
                        curr_min = i-l+1;
                    }
                    
                    s_map[s[l]]--;
                    if(s_map[s[l]] < t_map[s[l]]){
                        count--;
                    }
                    ++l;
                }
            }
        }
        if (!found) return "";
        
        return s.substr(res_begin, res_end-res_begin+1);
    }
};

// the hard part of this problem is 
// 1. The only window that is valid (containing all of t), must has both begin and end with letter in t
// 2. if t contains duplicates say "aa", valid window must contain same number of "aa"
//      -> so we need to have a map to count how many appears for each letters from t
// 3. How do we fastly know if all t letter are in the window?
//      -> keep a map to count the appears for the chars that in t, 
//.     -> a counter count to record **how many letter has the same number of letter in window vs. t map**
//. 4. *when we find a valid window, it is possible that the window could have more number than we required
//.     example, if t = "aab", s = "xyz[aaaaaab]", for the window, we finally get the b, but # of a is way more then required
//      so we need to have a while loop to move left util map['a'] < t_map['a']

// 有指针正常移 （进map）， 左指针伺机而动 （退元素出map），当window valid的时候计算
```