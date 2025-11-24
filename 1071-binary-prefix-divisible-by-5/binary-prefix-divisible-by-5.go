func prefixesDivBy5(nums []int) []bool {
    ans := make([]bool, len(nums))
    currPrefix := 0
    for i, val := range nums {
        currPrefix *= 2
        currPrefix += val
        currPrefix %= 5
        if currPrefix % 5 == 0 {
            ans[i] = true
        } else {
            ans[i] = false
        }
    }
    return ans
}