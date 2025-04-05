/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var actualLCA *TreeNode
func findLCA(nodes *map[int]bool, totalCount int, root *TreeNode) int {
    if root == nil {
        return 0
    }
    var val int
    if (*nodes)[root.Val] == true {
        val += 1
    }
    valLeft := findLCA(nodes, totalCount, root.Left)
    valRight := findLCA(nodes, totalCount, root.Right)
    sum := val + valLeft + valRight
    if sum == totalCount && actualLCA == nil {
        actualLCA = root
    }
    return sum
}
func findMaxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    return 1 + max(findMaxDepth(root.Left), findMaxDepth(root.Right))
}
func populateMapWithMaxDepthNodes(root *TreeNode, depth int, maxDepth int, nodes *map[int]bool) {
    if root == nil {
        return
    }
    if depth == maxDepth {
        (*nodes)[root.Val] = true
        return
    } else {
        populateMapWithMaxDepthNodes(root.Left, depth + 1, maxDepth, nodes)
        populateMapWithMaxDepthNodes(root.Right, depth + 1, maxDepth, nodes)
    }
}
func lcaDeepestLeaves(root *TreeNode) *TreeNode {
    maxDepth := findMaxDepth(root)
    actualLCA = nil
    nodes := make(map[int]bool)
    populateMapWithMaxDepthNodes(root, 1, maxDepth, &nodes)
    findLCA(&nodes, len(nodes), root)
    return actualLCA
}