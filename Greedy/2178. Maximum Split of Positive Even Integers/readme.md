# 2178. Maximum Split of Positive Even Integers

- 如是 n是even number， 那就一定是存在一种split的，因为大不了他自己。 如果是 odd number， 那一定不存在，因为 odd+odd还是odd，永远不可能变成even

- 因为我们想split最多的数字，所以贪心策略是， 我们从2开始加

- 如果 sum+i > finalSum 了， 那我们 i 就不能加。而是在 i-2 的位置加上 finalSum-sum。 这一步是这个贪心算法的精髓
