# 1944. Number of Visible People in a Queue

```
        |
|       |
|       |
|     | |
|   | | |
| | | | |
A B C D E
```

- 通过以上图 我们可以发现，A能看到 B，C，D，E
- 维护一个 从右往左的 单调递减栈
- A 是 D 的 next greater element，所以 A 入栈 要 pop 掉几个 element 都是 A 能看见的
- 而如果pop玩， 如果栈了还有元素 (E)， 那 A 也是可见的，所以要加上
