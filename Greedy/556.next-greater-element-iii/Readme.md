### compare Lexicographical Sequence
XXX 3 6 5 2 1 ==> XXX 3 [6 5 2 1] (find smallest number have seen backwards that is greater than curr -> 5)
              ==> XXX 5 [6 3 2 1]
              ==> XXX 5 [1 2 3 6]

***Algorithm***
1. we look from backward on each digit, if increasing, we cannot find a greate number
2. if we see some where decreasing (like 3 < 6), find smallest number have seen backwards that is greater than curr
3. replace curr and that number
4. to find the smallest number that start with XXX 5 [...], we need to sort [...]

```c++
class Solution {
public:
    int nextGreaterElement(int n) {
        // sort n each digit into vector
        vector<int> digits;
        while(n>0){
            digits.push_back(n%10);
            n = n/10;
        }   
        reverse(digits.begin(), digits.end());
        
        bool hasGreater = false;
        for(int i = digits.size()-1; i > 0; --i) {
            if(digits[i] > digits[i-1]){
                hasGreater = true;
                // the smallest that greater than curr
                int j = i;
                int smallestDigitGrt = i;
                while(j < digits.size()){
                    if(digits[j] > digits[i-1] && digits[j] < digits[smallestDigitGrt])
                        smallestDigitGrt = j;
                    ++j;
                }
                swap(digits[i-1], digits[smallestDigitGrt]);
                sort(digits.begin()+i, digits.end());
                break;
            }
        }

        if(!hasGreater)
            return -1;

        // convert digits back to number
        // also check if digit is fit in INT32
        long res = 0;
        for (int i=0; i<digits.size(); i++)
            res = res*10+digits[i];
        if (res > INT_MAX) return -1;

        return res;
    }
};


// 3, 5, 6, 4 
//  i
//    j
```