/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func allPossibleFBT(n int) []*TreeNode {
    if(n % 2 == 0){
        emptySlice := make([]*TreeNode,0)
        return emptySlice
    }
    emptySlice := make([]*TreeNode,0)
    if n == 1 {
        root := &TreeNode{}
        emptySlice = append(emptySlice,root)
        return emptySlice
    }
    remaining := n-1
    for i:=1;i<remaining;i+=2 {
        leftChilds := allPossibleFBT(i)
        rightChilds := allPossibleFBT(remaining-i)
        for _,lChild := range leftChilds {
            for _,rChild := range rightChilds {
                root := &TreeNode{
                    Val: 0,
                    Left: lChild,
                    Right : rChild,
                }
                emptySlice = append(emptySlice,root)
            }
        }
    }
    return emptySlice
}