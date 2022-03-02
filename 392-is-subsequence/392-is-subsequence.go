func isSubsequence(s string, t string) bool {
    m := len(s)
    n := len(t)
    if m == 0{
        return true
    }
    for i,j:=0,0;i<n;i++ {
        if t[i] == s[j] {
            j++
            if j == m {
                return true
            }
        } 
    }
    return false;
}