// Solved by Milon

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    ListNode solve(ListNode l1, ListNode l2, int carry) {
        if (l1 == null && l2 == null) return carry > 0? new ListNode(carry) : null;
        int val1 = (l1 != null? l1.val : 0);
        int val2= (l2 != null? l2.val : 0);
        int sum = (val1 + val2 + carry);
        int num = sum % 10;
        carry = sum / 10;
        
        ListNode nxt = solve(l1 == null? l1 : l1.next, l2 == null? l2 : l2.next, carry);
        ListNode node = new ListNode(num, nxt);
        return node;
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return solve(l1, l2, 0);
    }
}