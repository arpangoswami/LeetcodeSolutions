func transpose(matrix [][]int) [][]int {
    rows := len(matrix)
    cols := len(matrix[0])
    ans := make([][]int, cols)
    for i:=0;i<cols;i++ {
        ans[i] = make([]int, rows)
    }
    for i:=0;i<rows;i++ {
        for j:=0;j<cols;j++ {
            ans[j][i] = matrix[i][j]
        }
    }
    return ans
}