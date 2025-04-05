func subsetXORSum(nums []int) int {
    n := len(nums)
    maxNum := (1 << n)
    var totalSum int
    for i:= 0; i < maxNum; i++ {
        currSum := 0
        for j:= 0;j < n; j++ {
            if (i >> j) & 1 != 0 {
                currSum ^= nums[j]
            }
        }
        totalSum += currSum
    }
    return totalSum
}