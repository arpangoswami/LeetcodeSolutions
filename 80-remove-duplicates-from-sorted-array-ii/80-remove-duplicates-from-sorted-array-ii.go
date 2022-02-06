func removeDuplicates(nums []int) int {
    n := len(nums)
    count := 1
    idx := 1
    for i:= 1;i<n;i++ {
        if nums[i] == nums[i-1] {
            count++
            if count <= 2 {
                nums[idx] = nums[i]
                idx++
            }
        }else{
            count = 1
            nums[idx] = nums[i]
            idx++
        }
    }
    return idx
}