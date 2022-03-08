/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    if head == nil || head.Next == nil {
        return false
    }
    var first,second *ListNode
    for first,second = head,(head.Next);second != nil && second.Next != nil && first != second; first,second = first.Next,second.Next.Next{

    }
    return first == second
}