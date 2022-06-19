# 42. Trapping Rain Water

## two pass method (leftMost and rightMost)

- find leftMost and rightMost for index i

- sum += max(0, min(leftMost[i], rightMost[i]) - height[i])

## one pass method (monotonic decreasing stack)

- left <- second in the stack

- base <- height[s.top()]

- right <- i
