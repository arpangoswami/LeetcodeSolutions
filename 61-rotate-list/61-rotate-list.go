/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getLength(head *ListNode) int {
    ans := 0
    for curr := head;curr != nil;curr = curr.Next {
        ans++
    }
    return ans
}
func rotateRight(head *ListNode, k int) *ListNode {
    if head == nil{
        return head
    }
    k = k % getLength(head)
    if k == 0 {
        return head
    }
    k++
    curr_index := 1
    second := head
    for ;curr_index < k;curr_index++ {
        second = second.Next
    }
    first := head
    for ;second.Next != nil;second = second.Next {
        first = first.Next
    }
    ans := first.Next
    first.Next = nil
    second.Next = head
    return ans
}