/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    nextAns := swapPairs(head.Next.Next)
    nextVal := head.Next
    head.Next = nextAns
    nextVal.Next = head
    return nextVal
}