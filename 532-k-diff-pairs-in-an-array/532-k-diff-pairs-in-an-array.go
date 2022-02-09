type Pair struct {
    first int
    second int
}
func findPairs(nums []int, k int) int {
    present := make(map[int]bool)
    ans := 0
    taken := make(map[Pair]bool)
    for _,val := range nums {
        _,ok := present[val-k]
        pair1 := Pair {
            first : val,
            second: val-k,
        }
        pair2 := Pair {
            first : val-k,
            second: val,
        }
        pair3 := Pair {
            first : val,
            second: val+k,
        }
        pair4 := Pair {
            first : val+k,
            second: val,
        }
        _,ok2 := taken[pair1]
        _,ok3 := taken[pair2]
        if ok && !ok2 && !ok3{
            taken[pair1] = true
            taken[pair2] = true
            ans++
        }
        _,ok = present[val+k]
        _,ok2 = taken[pair3]
        _,ok3 = taken[pair4]
        if ok && !ok2 && !ok3{
            taken[pair3] = true
            taken[pair4] = true
            ans++
        }
        present[val] = true
    }
    return ans
}