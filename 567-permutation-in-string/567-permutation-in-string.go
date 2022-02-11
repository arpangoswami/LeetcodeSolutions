func isSame(freq1,freq2 [26]int) bool{
    for i:= 0;i<26;i++ {
        if freq1[i] != freq2[i] {
            return false;
        }
    }
    return true
}
func checkInclusion(s1 string, s2 string) bool {
    freq1 := [26]int{}
    freq2 := [26]int{}
    m := len(s1)
    n := len(s2)
    if m > n {
        return false
    }
    for _,val := range s1 {
        freq1[int(val)-97]++
    }
    for i := 0;i<m;i++ {
        freq2[int(s2[i]) - 97]++
    }
    for i:=m;i<n;i++{
        if isSame(freq1,freq2) {
            return true;
        }
        freq2[int(s2[i-m]) - 97]--
        freq2[int(s2[i]) - 97]++
    }
    if isSame(freq1,freq2) {
        return true
    }
    return false
}