func findMaxLength(nums []int) int {
    n := len(nums)
    for i:=0;i<n;i++ {
        if(nums[i] == 0){
            nums[i] = -1
        }
    }
    ans := 0
    lastIdx := make(map[int]int)
    currSum := 0
    lastIdx[0] = -1
    for idx,val := range nums {
        currSum += val
        if lastAppear,ok := lastIdx[currSum]; ok {
            if ans < (idx - lastAppear) {
                ans = idx - lastAppear
            }
        }else{
            lastIdx[currSum] = idx
        }
    }
    return ans
}