func countPairs(nums []int, k int) int {
    var ans int
    n := len(nums)
    for i:=0;i<(n-1);i++ {
        for j:=i+1;j<n;j++ {
            if nums[i] == nums[j] && (i*j % k == 0) {
                ans++
            }
        }
    }
    return ans
}