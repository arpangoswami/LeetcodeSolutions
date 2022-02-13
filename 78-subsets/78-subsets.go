func subsets(nums []int) [][]int {
    n := len(nums)
    maxSize := 1 << n
    ans := [][]int{}
    for i:=0;i<maxSize;i++ {
        subset := []int{}
        for j:=0;j<n;j++ {
            if (i >> j) & 1 == 1 {
                subset = append(subset, nums[j])
            }
        }
        ans = append(ans, subset)
    }
    return ans
}