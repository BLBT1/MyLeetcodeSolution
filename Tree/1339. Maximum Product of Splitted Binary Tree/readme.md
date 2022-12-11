# 1339. Maximum Product of Splitted Binary Tree

把每个节点都的左右edge砍断， 分成两个树来做乘积。我们知道左子树和右子树的合都是能通过postorder traversal传递上来的。那剩下的树的合是什么呢？就是整个树的合减去左子树的和或右子树的和。这个是可以提前求得的。 想到这点这个题就做出来了。
