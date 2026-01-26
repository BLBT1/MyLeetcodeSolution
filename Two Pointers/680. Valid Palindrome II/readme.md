# 680. Valid Palindrome II

- 双指针， 遇到一个不一致的 s[l] 和 s[r], 需要分别判断， s[l+1:r] 或 s[l:r-1] 是不是回文

```c++
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        if (s[l] != s[r]) 
            return isPalindromeAfterRemoveOne(s, l+1, r) || isPalindromeAfterRemoveOne(s, l, r-1);
        
        while(l < r) {
            if (s[l] == s[r]) {
                ++l; --r;
            } else {
                // remove at most one
                return isPalindromeAfterRemoveOne(s, l+1, r) || isPalindromeAfterRemoveOne(s, l, r-1);
            }
        }

        return true;
    }

    bool isPalindromeAfterRemoveOne(string s, int l, int r) {
        if (s[l] != s[r]) return false;
        while(l < r) {
            if (s[l] == s[r]) {
                ++l;
                --r;
            } else {
                return false;
            }
        }
        return true;
    }
};

```
