# 538. Convert BST to Greater Tree

- bst的一个特性是， inorder traversal的值是 从小到大排序的

- 我们从大到小跟新 树上的值，所以树的值可以是所有大于他的值的和

- 所以要用reversed inorder traversal， 也就是 right->mid->left

- 用一个field sum记录所有大于当前值的和
