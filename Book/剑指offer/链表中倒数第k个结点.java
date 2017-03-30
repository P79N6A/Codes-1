/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode FindKthToTail(ListNode head,int k) {
        int cnt = 0;
        ListNode pHead = head;
        while (pHead != null && cnt != k) {
            pHead = pHead.next;
            ++cnt;
        }
        if (cnt == k) {
            while (pHead != null) {
                head = head.next;
                pHead = pHead.next;
            }
            return head;
        }
        else return null;
    }
}