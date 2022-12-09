# 1026. Maximum Difference Between Node and Ancestor

对于树而言， 有两种传递信息的方式： top-down 和 bottom-up

- bottom-up 我们想拿到一个数字的孩子的信息时使用， 一般是postorder traversal

- top down 是我们需要一个node ancestor的信息的时候用， top down的信息可以用过 parameter 往下传递

此题用bottom up的话是 O(N^2), 用top-down是O(N), 需要注意的是， 往下传递的信息是node的ancestor的最大val和最小val。diff 可以通过class variable的方式记录。因为最初进来的parameter是 0和10000，所以要先更新一下啊mx和mi， 再找mxdiff和midiff
