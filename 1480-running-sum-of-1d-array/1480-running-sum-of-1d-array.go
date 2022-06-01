func runningSum(nums []int) []int {
    n := len(nums)
    ans := make([]int,n)
    sum := 0
    for i:=0;i<n;i++ {
        sum += nums[i]
        ans[i] = sum;
    }
    return ans;
}