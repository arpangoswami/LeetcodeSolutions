func compareArrays(freq1 [26]int,freq2 [26]int) bool{
    for i:=0;i<26;i++ {
        if(freq1[i] != freq2[i]){
            return false;
        }
    }
    return true;
}
func findAnagrams(s string, p string) []int {
    var ans []int
    len1 := len(s)
    len2 := len(p)
    if len1 < len2 {
        return ans
    }
    var freq1 [26]int
    var freq2 [26]int
    for i:=0;i<len2;i++ {
        freq2[int(p[i]) - int('a')]++
    }
    for i:=0;i<len2;i++ {
        freq1[int(s[i]) - int('a')]++
    }
    for i:=len2;i<len1;i++ {
        if(compareArrays(freq1,freq2)){
            ans = append(ans,i-len2);
        }
        freq1[int(s[i])-int('a')]++
        freq1[int(s[i-len2])-int('a')]--
    }
    if(compareArrays(freq1,freq2)){
        ans = append(ans,len1-len2);
    }
    return ans
}