func minimumOperations(nums []int) int {
    ans := 0
    for _, val:= range nums {
        if val % 3 != 0 {
            ans++
        }
    }
    return ans
}