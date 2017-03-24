/*
 public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
*/
public class Solution {

    public ListNode EntryNodeOfLoop(ListNode pHead) {
        if (pHead == null) return null;
        ListNode one = pHead;
        ListNode two = pHead;
        do {
            one = one.next;
            two = two.next;
            if (two == null) return null;
            two = two.next;
        } while (one != two);
        two = pHead;
        while (one != two) {
            one = one.next;
            two = two.next;
        } 
        return one;
    }
}