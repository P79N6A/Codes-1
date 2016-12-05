/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null) return null;
        int len = 1;
        ListNode bg = head;
        while (bg.next != null) {
            ++len;
            bg = bg.next;
        }
        if (len == 1) return head;
        
        int half = len / 2;
        bg = head;
        len = 1;
        while (len != half) {
            bg = bg.next;
            ++len;
        }
        ListNode nxtNode = bg.next;
        bg.next = null;
        
        head = sortList(head);
        nxtNode = sortList(nxtNode);
        
        ListNode nw = null;
        if (head.val < nxtNode.val) {
            nw = head;
            head = head.next;
        }
        else {
            nw = nxtNode;
            nxtNode = nxtNode.next;
        }
        ListNode save = nw;
        
        while (head != null && nxtNode != null) {
            if (head.val < nxtNode.val) {
                nw.next = head;
                head = head.next;
            }
            else {
                nw.next = nxtNode;
                nxtNode = nxtNode.next;
            }
            nw = nw.next;
        }
        
        if (nxtNode != null) head = nxtNode;
        
        nw.next = head;
        
        return save;
    }
}


//version 2
//使用两个指针找到中点，另外优化了剩下一个链表后的合并过程
public class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null) return null;
        if (head.next == null) return head;
        
        ListNode p1 = head, p2 = head;
        while (p1.next != null && p2.next != null && p2.next.next != null) {
            p1 = p1.next;
            p2 = p2.next.next;
        }
        
        p2 = p1.next;
        p1.next = null;
        
        head = sortList(head);
        p2 = sortList(p2);
        
        ListNode nw = null;
        if (head.val < p2.val) {
            nw = head;
            head = head.next;
        }
        else {
            nw = p2;
            p2 = p2.next;
        }
        ListNode save = nw;
        
        while (head != null && p2 != null) {
            if (head.val < p2.val) {
                nw.next = head;
                head = head.next;
            }
            else {
                nw.next = p2;
                p2 = p2.next;
            }
            nw = nw.next;
        }
        
        if (p2 != null) head = p2;
        
        nw.next = head;
        
        return save;
    }
}