func numSpecial(mat [][]int) int {
    rows := len(mat)
    cols := len(mat[0])
    rowMap := make([]int, rows)
    colMap := make([]int, cols)
    
    for i := 0 ; i < rows ; i ++ {
        for j := 0 ; j < cols ; j ++ {
            if mat[i][j] == 1 {
                rowMap[i]++
                colMap[j]++
            }
        }
    }
    ans := 0
    for i := 0 ; i < rows ; i ++ {
        for j := 0 ; j < cols ; j ++ {
            if mat[i][j] == 1 && rowMap[i] == 1 && colMap[j] == 1{
                ans++
            }
        }
    }
    return ans
}