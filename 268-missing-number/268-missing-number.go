func missingNumber(nums []int) int {
    sum := 0
    n := len(nums)
    shouldBeSum := (n*(n+1))/2
    for _,val := range nums {
        sum += val
    }
    return (shouldBeSum - sum)
}