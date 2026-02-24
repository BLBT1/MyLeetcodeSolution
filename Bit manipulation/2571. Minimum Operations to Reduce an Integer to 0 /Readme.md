1. 给一个数字，如果只能减， 那就是看 数字 binary 里有多少的 1

hamming wight calculation，如何快速消除数字末尾的1

```c++
n &= (n-1)
```
example => 
```
 10010
&10001
= 
 10000
```


### left bitwise in c++
```
1 << 0 == 1
1 << 1 == 2
1 << 2 == 4
1 << 3 == 8
```


## count number of 1s for positive numbers
```c++
// time: O(k), where k is number of 1s in the number
int countOnes(int n) {
    int res 0;
    while(n != 0){
        n &= (n-1);
        res += 1;
    }
    return res;
}
```

2. 这个题， 有时候加一位会让他消除的更快

example, something plus a number could reduce number of 1s
``` 
 10111
+    1
=> 11000
```
so we need to check this case


```c++
class Solution {
public:
    int minOperations(int n) {
        // int has 32 bits 
        int res = 0; 
        for(int i = 0; i < 31; ++i){
            // +1 because one operation needed to add a number
            if(countOnes(n+(1<<i))+1 <= countOnes(n)){
                n = n+(1<<i);
                res +=1;
            }
        }

        return res+countOnes(n);
    }

    int countOnes(int n){
        int cnt = 0;
        while(n!=0){
            n &= n-1;
            cnt++;
        }
        return cnt;
    }

    // use build-in functions
    // int countOnes(int x)
    // {
    //     return __builtin_popcount(x);
    // }
};

```



