import java.util.*;
/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Plus {
    public ListNode plusAB(ListNode a, ListNode b) {
        int add = 0;
        ListNode save = a;
        ListNode pre = null;
        while (a != null && b != null) {
            a.val += add + b.val;
            add = a.val / 10;
            a.val %= 10;
            pre = a;
            a = a.next;
            b = b.next;
        }
        if (b != null) {
            if (a != null)
           		a.next = b;
            else {
                if (pre != null)
                	pre.next = b;
                a = b;
            }
        }
        if (a != null && add == 1) {
            while (a != null) {
                if (a.val == 9) {
                    a.val = 0;
                    add = 1;
                }
                else {
                    a.val += 1;
                    add = 0;
                    break;
                }
                pre = a;
                a = a.next;
            }
        }
        if (add == 1) pre.next = new ListNode(1);
        return save;
    }
}