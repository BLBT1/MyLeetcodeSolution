# 82. Remove Duplicates from Sorted List II

- 遍历一个prev，看是否前面两个node的值相同

- 如果前面两个node的值相同，需要用一个指针把所有相同的node全部去了

```cpp
    if (prev->next->val == prev->next->next->val)
        {
            ListNode *p = prev->next;
            while (p->next != nullptr && p->val == p->next->val)
            {
                p = p->next;
            }
            prev->next = p->next;
        }
```
