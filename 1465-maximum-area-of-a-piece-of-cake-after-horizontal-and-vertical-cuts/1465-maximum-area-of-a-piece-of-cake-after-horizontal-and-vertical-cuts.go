func maxArea(h int, w int, horizontalCuts []int, verticalCuts []int) int {
    sort.Ints(horizontalCuts)
    sort.Ints(verticalCuts)
    const MOD uint64 = 1e9+7
    n := len(horizontalCuts)
    m := len(verticalCuts)
    maxHeight := horizontalCuts[0]
    if h - horizontalCuts[n-1] > maxHeight {
        maxHeight = h - horizontalCuts[n-1]
    }
    maxBreadth := verticalCuts[0]
    if w - verticalCuts[m-1] > maxBreadth {
        maxBreadth = w - verticalCuts[m-1]
    }
    for i:= 1;i<n;i++ {
        if (horizontalCuts[i] - horizontalCuts[i-1]) > maxHeight {
            maxHeight = horizontalCuts[i] - horizontalCuts[i-1]
        }
    }
    for i := 1;i<m;i++ {
        if (verticalCuts[i] - verticalCuts[i-1]) > maxBreadth {
            maxBreadth = verticalCuts[i] - verticalCuts[i-1]
        }
    }
    ans := uint64(maxHeight)*uint64(maxBreadth)
    ans %= MOD
    return int(ans)
}