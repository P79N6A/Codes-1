/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode Merge(ListNode list1,ListNode list2) {
        ListNode ans = new ListNode(0);
        ListNode ret = ans;
        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                ans.next = list1;
                list1 = list1.next;
            }
            else {
                ans.next = list2;
                list2 = list2.next;
            }
            ans = ans.next;
        }
        if (list1 == null || list2 == null) {
            if (list1 == null) {
                list1 = list2;
            }
            ans.next = list1;
        }
        return ret.next;
    }
}