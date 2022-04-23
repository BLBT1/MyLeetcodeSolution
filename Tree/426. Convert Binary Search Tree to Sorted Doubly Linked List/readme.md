# 426. Convert Binary Search Tree to Sorted Doubly Linked List

- 双向链表 + 头尾相连。所以我们要更新 一个prev， 一个 head 和一个tail。

- 把 curr->left = prev, prev->right = curr

- prev 每步更新， 每次更新prev 到 curr root； 如果是 prev是 prev， 则不用做别的操作

- 怎么更新tail？ 每次我们都把tail都更新成curr， 这样结束的时候tail肯定是最后一个node
