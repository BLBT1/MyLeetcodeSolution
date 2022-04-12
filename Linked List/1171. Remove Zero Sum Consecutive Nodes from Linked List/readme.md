# 1171. Remove Zero Sum Consecutive Nodes from Linked List

- prefix sum 和 linked list的结合， greedy jump， 有点像2sum的感觉，看到要删除一个连续sequence 的node 和为 0，就要往前缀和的方向思考

- 考虑以下linked list

```cpp
0 -> 1 -> 2 -> 3 -> -2 -> -3 -> 9
d
```

- 我们可以找到每个node对应的前缀和

```cpp
nodes: 0 1 2 3 -2 -3 9
prefix 0 1 3 6  4  1 10  
```

- 注意到node 1 和 node -3 对应的prefix sum都是 1， 说明 （2 3 -2 -3)sequence 的 sum 是 0.

- 如果我们用 hashmap记录每个node对应的前缀和，那我们就可以在链表里删去这一段， 也就是直接连接到 -3 之后的一个node

- 因为可能有多个数有相同的前缀和， 我们像记录的是最后的一个在map里
