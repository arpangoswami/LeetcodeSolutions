func searchMatrix(matrix [][]int, target int) bool {
    rows := len(matrix)
    if rows == 0 {
        return false
    }
    cols := len(matrix[0])
    if cols == 0{
        return false
    }
    // x := 0
    // y := cols-1
    for x,y:=0,cols-1;x < rows && y >= 0; {
        if matrix[x][y] == target {
            return true
        }else if matrix[x][y] > target {
            y--
        }else{
            x++
        }
    }
    return false
}