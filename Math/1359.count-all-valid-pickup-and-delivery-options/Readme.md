
### 2 problem we need to consider from the high level
1. How many number of pickup sequence are there
    - n!
    - if we pick Pi at begin, there are P[n-1] remaining options

2. For a pickup sequence, how many number of different ways to arrange deliverys

example
n = 3,

how many options for arange D1?
- it cannot put at idx 0, but can be put anywhere else

P1 P2 X  P3 X --> Xs are D2/D3 --> 2n-1 (-1 because cannot put at idx0)

how many options for arrange D2?
- it cannot be put at any place it has not been for first chosen delivery and pickup pairs (in or case {P1,D1}). so it has 2n-3 options

- so for a n, the number of different ways to arrange deliverys = 
    (2n-1).(2n-3).(2n-5)...1

## Total options = number of different pickup sequence * number of delivery arrangement for a sequence

```c++
class Solution {
public:
    int countOrders(int n) {
        long res = 1;
        int MOD = 1e9+7;

        // all permutations
        for(long i = n; i >= 1; --i){
            res = (res*i)%MOD;
        }     

        // calculate all possible permutations for a pickup sequence
        for(long i = 2*n-1; i >= 1; i = i-2){
            res = (res*i)%MOD;
        }
        return res;
    }
};
```
