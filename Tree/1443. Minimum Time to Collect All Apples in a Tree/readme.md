# 1443. Minimum Time to Collect All Apples in a Tree

## 核心思想

除了0之外的每个点而言：我们需要思考他需不需要出现在最后的path里， 如果出现那就是1去1回， res += 2

那对于任何点，出现在path里有两种情况：

1. it self has an apple
2. its subtree has an apple
         => use postorder traversal
         =>  if cost >= 2, then a subtree has at least an apple

Therefore, each node：

```cpp
        if(hasApple[curr] || res > 0)
            if(curr != 0) // started from 0 index, no need to move
                res += 2;
```
