# 456. 132 Pattern

- 假设 132 pattern存在，那假设每个可能的点都是 3 个位置， 那 用greedy的思想， 左边的 1 是左边 最小的， 而右边的2是 右边小于当前element中最大的

- 所以， 对于每个 i， 都要找到左边最小， 用 O（N）

- 而要找到右边小于当前element中最大的，就要用一个单调递减栈, 从右往左， 如图

```
//           |
// |         |
// |         |
// |       | |
// |   |   | |
// | | | | | |
    
    // s decreasing stack 
    //6 3 2 1 5 => the last one to be popped in the stack is 右边小于当前element中最大
```
