# 99. Recover Binary Search Tree

首先因为是bst，所以用 inorder traversal， 其次，如果没有swap， 那整个排序完是单调递增的，而两处swap的nodes就在arr[i-1] > arr[i] 的地方，但是有两个情况需要讨论

情况1： 两个点不相邻

```cpp
    f               
                x
            x
        x
                    s    
x
```

- 第一个点是 f的位置
- 第二个异常点是 s的位置， 要分别记录

情况2： 两个点相邻

```cpp
                x
            x
    f
        s                        
x
```

- 所以记录第一个异常点后，要先暂时把第二个异常点的位置先暂时记录为第一个异常点之后

最后， 因为要prev，初始时nullptr， 我们可以用一个 dummy node with INT_MIN
