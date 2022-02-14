/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func maxDepth(root *Node) int {
    if(root == nil){
        return 0
    }
    ans := 0
    var childVal int
    for _,child := range (*root).Children {
        childVal = maxDepth(child)
        if childVal > ans {
            ans = childVal
        }
    }
    return 1+ans
}