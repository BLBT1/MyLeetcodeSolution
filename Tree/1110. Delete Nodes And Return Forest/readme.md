# 1110. Delete Nodes And Return Forest

- postorder traversal

- 拿到的是左右两边已经处理好的子树

- 处理当前node， 如果是delete的目标，把左右子树加进res

- 传上去处理好多子树，如果当前需要delete，那就传nullptr
