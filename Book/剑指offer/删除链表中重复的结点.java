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
    public ListNode deleteDuplication(ListNode pHead) {
        ListNode ans = new ListNode(0);
        
        ListNode cur = ans;
        ListNode nxt = pHead;
        while (nxt != null) {
            int cnt = 0;
            while (nxt.next != null && nxt.val == nxt.next.val) {
                nxt = nxt.next;
                ++cnt;
            }
            if (cnt == 0) {
                cur.next = nxt;
                cur = cur.next;
            }
            else if (nxt.next == null) {
                cur.next = null;
            }
            nxt = nxt.next;
        }
        
        return ans.next;
    }
}