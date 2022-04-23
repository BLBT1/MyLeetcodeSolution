# 450. Delete Node in a BST

需要考虑三种情况：

1. 如果 key 的 node是leaf， 那直接删掉就可以了
2. 如果 key 的 node 有一个child， 那删掉那个node，把唯一的孩子接上去就可以了
3. 如果 key 的 node 有两个 children。 那可以把 bst 想象成 inorder traversal 就是一个 sorted linked list。 如果是linked list， 那我们可能找到 node->next。 同理，在bst里我们也要找到 inorder traversal 的 next， 也就是 node的右子树的最左的点, 返回他即可

### time

O(logN)
