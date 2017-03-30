/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
// 将链表想像成如下样子：
// null -> 1 -> 2 -> 3
public class Solution {
	public ListNode ReverseList(ListNode head) {
        ListNode pre = null;
        ListNode nxt = null;
        while (head != null) {
        	nxt = head.next;
        	head.next = pre;
        	pre = head;
        	head = nxt;
        }
        return pre;
    }
}