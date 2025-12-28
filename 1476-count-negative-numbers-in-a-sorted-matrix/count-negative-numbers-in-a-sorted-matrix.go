func countNegatives(grid [][]int) int {
    rows := len(grid)
    cols := len(grid[0])
    rowIdx := 0
    colIdx := cols - 1
    ans := 0
    for ;rowIdx < rows && colIdx >=0; {
        if(grid[rowIdx][colIdx] < 0){
            ans += (rows - rowIdx)
            colIdx--
        }else{
            rowIdx++
        }
    }
    return ans
}