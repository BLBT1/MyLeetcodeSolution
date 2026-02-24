# 424. Longest Repeating Character Replacement

```c++
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> countChar(26, 0);
        int l = 0;
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            countChar[s[i]-'A']++;
            while(!isValidWindow(countChar, k)){
                countChar[s[l]-'A']--;
                ++l;
            }
            
            res = max(res, i-l+1);
        }
        
        return res;
    }

    // O(26)
    bool isValidWindow(vector<int> &countChar, int k) {
        // sum = sum of all count 
        // count of max element
        int maxCount = 0; 
        int sum = 0;
        for (auto count: countChar){
            maxCount =max(maxCount, count);
            sum += count;
        }
        return sum-maxCount <= k;
    }
};


// longest repeating substring with k different element

// 1


// we can use an array because it mentioned only upper case letters
// vector<> -> appear # of each element in window 
// A -> 3
// B -> 2

// AABABBA
//    l
//     i

// how to calculate res?
// max_curr = max_element(appear) + how many difference

// if difference > k, move l to right until valid window again

```