func addDigits(num int) int {
    ans := 0
    for {
        for {
            ans += num % 10
            num /= 10
            if num <= 0 {
                break
            }
        }
        num = ans
        ans = 0
        if num < 10 {
            break
        }
    }
    ans = num
    return ans
}