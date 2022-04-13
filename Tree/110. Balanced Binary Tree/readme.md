# 110. Balanced Binary Tree

- 根据定义， 如果左子树和右子树的深度差大于1，那树就不balanced 了

- 所以我们需要用写一个helper来算每个node的最大深度

- 因为深度都是正的，我们可以用返回-1来表示这个node不 balanced了

- 一个树 有任何一个node不balance，那整个树就不 balance了
