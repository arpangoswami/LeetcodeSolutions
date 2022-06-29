func minIncrementForUnique(nums []int) int {
    sort.Ints(nums)
    n := len(nums)
    duplicates := 0
    ans := 0
    for i:=1;i<n;i+=1 {
        if nums[i] == nums[i-1] {
            duplicates++
            ans -= nums[i]
        }else{
            option1 := nums[i] - nums[i-1] - 1
            option2 := duplicates
            var numbers int
            if option1 < option2 {
                numbers = option1
            }else {
                numbers = option2
            }
            add := numbers * nums[i-1] + (numbers*(numbers+1))/2
            duplicates -= numbers
            ans += add
        }
    }
    if duplicates > 0 {
        ans += duplicates * nums[n-1] + (duplicates*(duplicates+1))/2
        duplicates = 0
    }
    return ans
}