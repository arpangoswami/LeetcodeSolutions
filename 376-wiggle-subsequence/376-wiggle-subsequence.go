func wiggleMaxLength(nums []int) int {
    n := len(nums)
    up := 1
    down := 1
    for i:=1;i<n;i++ {
        if nums[i] > nums[i-1] {
            up = 1+down
        }else if nums[i] < nums[i-1] {
            down = 1 + up
        }
    }
    if up > down {
        return up
    }
    return down
}