/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func treeBuilder(preorder []int,inorder []int,idx *int,mp map[int]int,left,right int) *TreeNode{
    if left > right {
        return nil
    }
    inorderIdx := mp[preorder[*idx]]
    root := &TreeNode{Val: inorder[inorderIdx]}
    *idx += 1
    root.Left = treeBuilder(preorder,inorder,idx,mp,left,inorderIdx-1)
    root.Right = treeBuilder(preorder,inorder,idx,mp,inorderIdx+1,right)
    return root
}
func buildTree(preorder []int, inorder []int) *TreeNode {
    n := len(inorder)
    mp := make(map[int]int)
    for idx,val := range inorder {
        mp[val] = idx;
    }
    idx := 0
    return treeBuilder(preorder,inorder,&idx,mp,0,n-1)
}