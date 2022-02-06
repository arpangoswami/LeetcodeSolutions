func minimumTime(s string) int {
    n := len(s)
    ans := n
    left := 0
    for idx,val := range s {
        //Cost to remove all from left -> idx+1
        //left = min(left + 2,idx+1)
        //res = min(res,left + n - idx - 1)
        left += 2 * (int(val) - '0')
        if left > (idx + 1) {
            left = 1 + idx
        }
        if ans > (left + n - idx - 1) {
            ans = left + n - idx - 1
        }
    }
    return ans
}