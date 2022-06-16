# 304. Range Sum Query 2D - Immutable

### Build Presum

- presum[m+1][n+1]

- presum[i+1][j+1] = presum[i][j+1] + presum[i+1][j] - presum[i][j] + mat[i][j];

### query

- presum[row2+1][col2+1] - presum[row2+1][col1] - presum[row1][col2+1] + presum[row1][col1];

- 自己画个图片看看就清楚了
