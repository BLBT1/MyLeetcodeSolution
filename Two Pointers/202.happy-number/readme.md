
## brute force
Just stimulate with a hash set. When we see a number repeated, there is a cycle
Time = O(logN)
Space = O(logN)


```c++
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n != 1) {
            if(seen.find(n) != seen.end())
                return false;
            seen.insert(n);

            int sum = 0;
            while(n != 0){
                int d = n%10;
                sum += d*d;
                n /= 10;
            }

            n = sum;
        }
        return true;
    }
};
```


### fast&slow pointer
We can consider this problem as a faster&slow pointers. 
One pointer is to get 2 next number once, one pointer to get one next number. We can check 2 point meet or not
If fast pointer reaches 1, it is happy number.

Time = O(logN)
Space = O(1)

```c++
class Solution {
public:
    bool isHappy(int n) {
        int fast = getNext(n);
        int slow = n;
        while(fast != 1) {
            fast = getNext(getNext(fast));
            slow = getNext(slow);
            if(slow == fast) return false; // 2 pointer meet, there is a cycle
        }
        return true;
    }

    int getNext(int n){
        int sum = 0;
        while(n != 0){
            int d = n%10;
            sum += d*d;
            n /= 10;
        }
        return sum;
    }
};
```

