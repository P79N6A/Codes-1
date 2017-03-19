/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode FindFirstCommonNode(ListNode pHead1, ListNode pHead2) {
        ListNode th1 = pHead1, save1 = null, th2 = pHead2, save2 = null;
        int cnt1 = 0, cnt2 = 0;
        while (th1 != null) {
            save1 = th1;
            th1 = th1.next;
            ++cnt1;
        }
        while (th2 != null) {
            save2 = th2;
            th2 = th2.next;
            ++cnt2;
        }
        if (cnt1 == 0 || cnt2 == 0 || save1 != save2) {
            return null;
        }
        
        if (cnt1 < cnt2) {
            int temp = cnt1;
            cnt1 = cnt2;
            cnt2 = temp;
            save1 = pHead1;
            pHead1 = pHead2;
            pHead2 = save1;
        }
        
        int step = cnt1 - cnt2;
        while (step != 0) {
            pHead1 = pHead1.next;
            --step;
        }
        while (pHead1 != pHead2) {
            pHead1 = pHead1.next;
            pHead2 = pHead2.next;
        }
        return pHead1;
    }
}