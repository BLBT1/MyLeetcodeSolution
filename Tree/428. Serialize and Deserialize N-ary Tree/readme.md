# 428. Serialize and Deserialize N-ary Tree

和 lc297 一样的做法， 用preorder traversal， 唯一的不同是这里有一个 vector的pointer， 同时serialize的时需要多存每个点有几个children， 如果是 null， 就存0个child
