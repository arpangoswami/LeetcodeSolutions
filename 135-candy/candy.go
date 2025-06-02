func candy(ratings []int) int {
    n := len(ratings)
    ans := make([]int,n)
    ans[0] = 1
    for i:=1;i<n;i++ {
        if ratings[i] > ratings[i-1] {
            ans[i] = 1+ans[i-1]
        } else {
            ans[i] = 1
        }
    }
    sum := ans[n-1]
    for i:=n-2;i>=0;i-- {
        if ratings[i] > ratings[i+1] {
            val := 1+ans[i+1]
            if val > ans[i] {
                ans[i] = val
            }
        }
        sum += ans[i]
    }
    return sum
}