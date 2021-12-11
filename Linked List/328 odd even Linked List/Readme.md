# 328 Odd Even Linked List

## 需要注意：

1. 当前current node为偶位置，需要把他的next接到他的prev，这操作需要我们从一开就维护一个prev的指针指向curr之前的node。这里需要注意：
- 当curr为偶位置，则当前node会被移除，所以prev并不需要更新
- 只有当curr为奇数位置，需更新 prev = prev->next;

2. 使用一个dummy node对移除的偶位置节点进行暂存，最后再append到list的末尾。对于dummy node的使用在linked list的题里很长见，一定要熟能生巧！

