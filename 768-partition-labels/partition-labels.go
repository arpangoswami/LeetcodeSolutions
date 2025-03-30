func partitionLabels(s string) []int {
    lastIdx := make([]int, 26)
    for i:= 0; i < 26; i++{
        lastIdx[i] = -1
    }
    n := len(s)
    for i := n-1; i >= 0; i--{
        if lastIdx[s[i] - 'a'] == -1 {
            lastIdx[s[i] - 'a'] = i
        }
    }
    ans:= []int{}
    for i :=0 ; i<n ; {
        startPos := i
        lastPos := lastIdx[s[i] - 'a']
        currLength := lastPos - startPos + 1
        for j:=startPos;j<=lastPos;j++{
            lastPosCurr := lastIdx[s[j] - 'a']
            if lastPosCurr > lastPos {
                lastPos = lastPosCurr
                currLength = lastPos - startPos + 1
            }
        }
        i = lastPos + 1
        ans = append(ans, currLength)
    }
    return ans
}