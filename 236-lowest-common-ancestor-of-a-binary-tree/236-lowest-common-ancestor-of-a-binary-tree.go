/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    if root == nil {
        return nil
    }  
    if root == p || root == q {
        return root
    }
    leftAns := lowestCommonAncestor(root.Left,p,q)
    rightAns := lowestCommonAncestor(root.Right,p,q)
    if leftAns != nil && rightAns != nil {
        return root
    }
    if leftAns != nil {
        return leftAns
    }
    return rightAns
}