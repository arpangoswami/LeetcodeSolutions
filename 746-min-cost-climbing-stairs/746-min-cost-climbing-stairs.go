func minCostClimbingStairs(cost []int) int {
    secLast := cost[0]
    last := cost[1]
    for i:=2;i<len(cost);i++ {
        var minVal int
        if secLast < last {
            minVal = secLast
        }else{
            minVal = last
        }
        temp := cost[i]+minVal
        secLast = last
        last = temp
    }
    if secLast < last {
        return secLast
    }
    return last
}