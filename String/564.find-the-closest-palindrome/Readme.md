# 564. Find the Closest Palindrome

## Key Insight

The nearest palindrome is always one of two candidates:
- **nextSmaller**: the largest palindrome < n
- **nextGreater**: the smallest palindrome > n

Pick whichever is closer. On a tie → pick the smaller one.

---

## How to Construct Each Candidate

Both follow the same 2-step pattern:

1. **Mirror the first half** onto the second half → free candidate
   - If mirroring gives a strictly smaller/greater result → done ✓
   - If not (mirroring gave equal or wrong direction) → need to adjust

2. **Adjust the first half by ±1**, then mirror again
   - `nextSmaller`: first-half `- 1`, then mirror
   - `nextGreater`: first-half `+ 1`, then mirror

3. **Handle digit-length overflow:**
   - Underflow (e.g. `10 → 00`): return `"999...9"` (m-1 nines)
   - Overflow (e.g. `9 → 11`): return `"100...01"` (m+1 digits)

---

## Implementation Notes

- **Middle index** for ±1 propagation: `(m-1)/2` — works for both odd and even length
- **Carry simulation**: walk left from center, propagate carry/borrow like grade-school arithmetic
- Common bugs:
  - Character arithmetic: `n[i] + 10 - carry` (no extra `- '0'`)
  - Must apply the carry/borrow in the `else` branch before `break`

---

## Examples

```
123  → mirror → 121 ✓ (smaller)      nextGreater: 131
9001 → mirror → 9009 (larger, skip)  → first-half 90-1=89 → 8998
1299 → mirror → 1221 (smaller, skip) → first-half 12+1=13 → 1331
10   → first-half 1-1=0 → overflow   → return "9"
9    → first-half 9+1=10 → overflow  → return "11"
```

```c++
class Solution {
public:
    string nearestPalindromic(string n) {
        string smaller = nextSmaller(n);
        string greater = nextGreater(n);
        if(stoll(n) - stoll(smaller) <= stoll(greater) - stoll(n))
            return smaller;
        return greater;
    }

    // get next smaller palindrome
    string nextSmaller(string n) {
        int m = n.size();
        string flip = n;
        // first flip the first half to the second half
        for(int i = 0, j = m-1; i < j; ++i, --j){
            flip[j] = flip[i];
        }

        // check if it is smaller
        if(stoll(flip) < stoll(n))
            return flip;
        
        // else, we get a larger number after flip
        //9001 -> 9009
        // we need to have the first half -1 and flip again
        // [90] 01 -> [89]01 -> 8998

        // do a substruction simulation
        int carry = 1;
        for(int i = (m-1)/2; i >= 0; --i){
            if(n[i]-'0'- carry < 0){
                n[i] = n[i]+10 - carry;
                carry = 1;
            } else{
                n[i] = n[i] - carry;
                carry = 0;
                break;
            }
        }

        // no overflow or shrink on digit
        // only the first digit cannot be 0 if number has more than 1 digit
        if(n[0] == '0' && m > 1){
            // if we run over like -> 10 -> 00 (but anwser is 9)
            // we need the largest palindrome with less digit
            string s;
            for(int i= 0; i < m-1; ++i){
                s.push_back('9');
            }
            return s;
        }

        // flip again
        for(int i = 0, j = m-1; i < j; ++i, --j){
            n[j] = n[i];
        }
        return n;
    }


        // get next greater palindrome
    string nextGreater(string n) {
        int m = n.size();
        string flip = n;
        // first flip the first half to the second half
        for(int i = 0, j = m-1; i < j; ++i, --j){
            flip[j] = flip[i];
        }

        // check if it is greater
        if(stoll(flip) > stoll(n))
            return flip;
        
        // else, we get a samller number after flip
        // 1299 -> 1221
        // do a additon simulation
        int carry = 1;
        for(int i = (m-1)/2; i >= 0; --i){
            if(n[i]-'0'+ carry == 10){
                n[i] = n[i] + carry - 10;
                carry = 1;
            } else {
                n[i] = n[i] + carry;
                carry = 0;
                break;
            }
        }

        if (carry != 1) {
            // flip again
            for(int i = 0, j = m-1; i < j; ++i, --j){
                n[j] = n[i];
            }
            return n;
        }

        // if we run over like 9->11
        // we need the largest palindrome with more digit
        string s;
        for(int i = 0; i < m+1; ++i){
            if(i == 0 || i == m)
                s.push_back('1');
            else
                s.push_back('0');
        }
        return s;
    }
};

```




