func searchRange(nums []int, target int) []int {
    ans := make([]int,2)
    ans[0] = -1
    ans[1] = -1
    n := len(nums)
    low := 0
    high := n-1
    left := n
    for ;low<=high;{
        mid := (low+high)/2
        if nums[mid] == target {
            left = mid
            high = mid-1
        }else if nums[mid] > target {
            high = mid-1
        }else{
            low = mid+1
        }
    }
    if left == n {
        return ans
    }
    ans[0] = left
    low = 0
    high = n-1
    right := left
    for ;low<=high; {
        mid := (low+high)/2
        if nums[mid] == target {
            right = mid
            low = mid+1
        }else if nums[mid] > target {
            high = mid-1
        }else{
            low = mid+1
        }
    }
    ans[1] = right
    return ans
}