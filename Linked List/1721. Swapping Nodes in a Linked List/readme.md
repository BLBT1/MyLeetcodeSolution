# 1721. Swapping Nodes in a Linked List

- 这题最重要的是要想到，r 指针需要走到距离最后一个node k 的位置， 那也就是 r 需要走 list.length - k 次

- 想到这里， 我们可以用以下代码

```cpp
        while (curr != nullptr)
        {
            if (cnt < k)
            {
                l = l->next;
            }
            if (cnt > k)
            {
                r = r->next;
            }
            curr = curr->next;
            cnt++;
        }
```
