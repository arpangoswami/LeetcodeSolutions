func maxScore(cardPoints []int, k int) int {
    n := len(cardPoints)
    possibleAns := 0
    for i:=0;i<k;i++ {
        possibleAns += cardPoints[i]
    }
    ans := possibleAns
    ptr := k-1
    for i:=n-1;i>=(n-k);i--{
        possibleAns -= cardPoints[ptr];
        ptr--;
        possibleAns += cardPoints[i]
        if possibleAns > ans {
            ans = possibleAns
        }
    }
    return ans
}