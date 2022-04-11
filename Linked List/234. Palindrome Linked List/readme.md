# 234. Palindrome Linked List

1. 找到链表中点，或者中点偏左的点（如果链表有双数个）

```cpp
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
```

2. 切断链表且reverse第二段

3. 双指针一一对比

4. 注意，这里切断后的两链表个数不一样是可以的，[1,0,1]也是回文
