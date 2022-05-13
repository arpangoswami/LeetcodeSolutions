/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Next *Node
 * }
 */
func connect(root *Node) *Node {
	if root == nil {
		return root
	}

	head := root
	for head != nil {
		dummyHead := &Node{}
		cur := dummyHead
		// * Traverse the nodes at a specific level
		for head != nil {
			if head.Left != nil {
				cur.Next = head.Left
				cur = cur.Next
			}
			if head.Right != nil {
				cur.Next = head.Right
				cur = cur.Next
			}

			head = head.Next
		}

		head = dummyHead.Next
	}

	return root
}
// func connect(root *Node) *Node {
	
// }