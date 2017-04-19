import java.util.*;

/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
// 还可以利用快慢指针
public class Palindrome {
    public boolean isPalindrome(ListNode pHead) {
        if (pHead == null) return true;
        ListNode pre = null;
        ListNode cur = null;
        ListNode go = pHead;
        while (go != null) {
            cur = new ListNode(go.val);
            cur.next = pre;
            pre = cur;
            go = go.next;
        }
        while (pHead != null) {
            if (pHead.val != cur.val) return false;
            pHead = pHead.next;
            cur = cur.next;
        }
        return true;
    }
}