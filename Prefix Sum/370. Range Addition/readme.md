# 370. Range Addition

- 如果每次跟新， 都想象成从 start 到 nums 最后一个数字， 这样我们只需跟新开头， 因为用 running sum 可以返回想要的跟新

- 同样， 在 end+1 的位置需要 -=val，running sum end 之后的数字就能复原

- 最后用prefix sum 得出结果，因为每次更新都是线性的
