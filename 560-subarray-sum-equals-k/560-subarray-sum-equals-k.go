func subarraySum(nums []int, k int) int {
    freqMap := make(map[int]int)
    freqMap[0] = 1
    ans := 0
    currSum := 0
    for _,val := range nums {
        currSum += val
        value,present := freqMap[currSum-k]
        //fmt.Println(currSum,currSum-val,value)
        if present {
            ans += value
        }
        freqMap[currSum]++;
    }
    return ans
}