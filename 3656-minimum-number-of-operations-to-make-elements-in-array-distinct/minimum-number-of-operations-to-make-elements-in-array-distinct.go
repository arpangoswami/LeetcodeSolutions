func minimumOperations(nums []int) int {
    n := len(nums)
    freqMap := make(map[int]int)
    mul := 0
    for _, val := range nums {
        freqMap[val]++
    }
    for _, val := range freqMap {
        if val > 1 {
            mul++
        }
    }
    if mul == 0 {
        return 0
    }
    var ans int
    for i:=0 ; i < n ; i++ {
        if i % 3 == 0 {
            ans++
        }
        if freqMap[nums[i]] == 2 {
            mul--
        }
        freqMap[nums[i]]--
        if mul == 0 {
            return ans
        }
    }
    return ans
}