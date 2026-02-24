注意
1. swap是必须的，所以要最后check 有没有同样两个以上的char在s里 以及有没有swap过 
    - (aaab and aaab is valid）(aa and aa is valid) but (ab and ab) is invalid

```c++
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        
        int count[26];
        int n = s.size();
        int i = 0;
        bool swapped = false;
        char have = '#';
        char want = '#';
        while(i < n){
            if(s[i] != goal[i]){
                if (have != '#') {
                    if (swapped)
                        return false;
                    if (s[i] == want && goal[i] == have) {
                        swapped = true;
                    } else{
                        return false;
                    }
                } 
                have = s[i];
                want = goal[i];
            }

            count[s[i]-'a']+=1;
            ++i;
        }
         
        
        if(have == '#'){
            for(int i = 0; i < 26; ++i){
                // check if any letter has the same to swap
                if (count[i]>=2)
                    return true;
            }
            // if had same letter, can still swap
            return false;
        }
        
        return swapped;
    }
};


// diff = 'a' 
// want = 'c'
// abcd
//   i   

// cbad
//   j

```