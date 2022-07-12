func recSolve(idx,one,two,three,four,sum int,matchsticks []int)bool {
    if idx == len(matchsticks){
        if one == two && one == three && one == four {
            return true;    
        }
        return false;
    }
    if one > sum/4 || two > sum/4 || three > sum/4 || four>sum/4 {
        return false;
    }
    flag := recSolve(idx+1,one+matchsticks[idx],two,three,four,sum,matchsticks)
    if flag {
        return true;
    }
    flag = recSolve(idx+1,one,two+matchsticks[idx],three,four,sum,matchsticks)
    if flag {
        return true;
    }
    flag = recSolve(idx+1,one,two,three+matchsticks[idx],four,sum,matchsticks)
    if flag {
        return true
    }
    return recSolve(idx+1,one,two,three,four+matchsticks[idx],sum,matchsticks)
}
func makesquare(matchsticks []int) bool {
    sort.Sort(sort.Reverse(sort.IntSlice(matchsticks)))
    sum := 0
    for _,val := range matchsticks {
        sum += val
    }
    if sum % 4 != 0 || len(matchsticks) < 4 || matchsticks[0] > sum/4{
        return false
    }
    return recSolve(0,0,0,0,0,sum,matchsticks)
}