func numRabbits(answers []int) int {
    freqMap := make(map[int]int)
    for _, v := range answers {
        freqMap[v]++
    }
    ans := 0
    for key, val := range freqMap {
        ceilingMul := (val + key)/(key+1)
        ans += ceilingMul * (key+1)
    }
    return ans
}