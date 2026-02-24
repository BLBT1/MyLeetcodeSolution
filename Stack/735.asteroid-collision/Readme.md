The pos numbers -> , the neg numbers <-

We want to cross out the smaller abs value items

This process feels like left right are matching and compared (like parathesis), 
Also because the later (right in array) postive numbers would be compared first, so we need a stack for this purpose.

## The hard part is to determine the output.
**pos is always after negatives in the final output (if any negatives remains)**
 - (if pos is greater, has neg after it, it would be exploded)


###optimize
// We can use vector as a stack, and check the back() of the vector. So we vector itself can be the res;
// if pos, push in vector as no collision
// if neg, check starting from the back for the vector, while the back is less than abs of curr neg value, remove the back

```c++
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> pos;
        vector<int> neg;
        for(int i = 0; i < asteroids.size(); ++i){
            if(asteroids[i] > 0) 
                pos.push(asteroids[i]);
            else{
                int curr = asteroids[i];
                bool isExploded = false;
                while(!pos.empty()){
                    if (pos.top() > abs(curr)){
                        isExploded = true;
                        break;
                    } else if(pos.top() == abs(curr)){
                        isExploded = true;
                        pos.pop();
                        break;
                    } else{
                        pos.pop();
                    }
                }

                if(!isExploded){
                    neg.push_back(curr);
                }
            }
        }

        vector<int> posRes;
        while(!pos.empty()){
            posRes.push_back(pos.top());
            pos.pop();
        }
        reverse(posRes.begin(), posRes.end());

        for(auto p: posRes){
            neg.push_back(p);
        }
        return neg;
    }
};

// [5,10,-5]

// 5 -> 10 ->  <- -5


// [3,5,-6,2,-1,4]​​​​

// ​​​3 -> 5 -> <- -6 2 -> <- -1  4 ->

// for each value, check if any pos stack has value, compare, and store curr value into stack
// positives [3, 5]

// pos is always after negatives in the final output (if any negatives remains)
// (if pos is greater, has neg after it, it would be exploded)
// 
```
