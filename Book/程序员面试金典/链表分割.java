import java.util.*;


class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
public class Partition {
    
    public static void swap(ListNode x, ListNode y) {
        int temp = x.val;
        x.val = y.val;
        y.val = temp;
    }
    
    public static ListNode partition(ListNode pHead, int x) {
        if (pHead != null && pHead.next != null) {
            ListNode min = new ListNode(0);
            ListNode max = new ListNode(0);
            ListNode ret = min, lk = max;
            ListNode head = pHead;
            while (head != null) {
            	if (head.val < x) {
            		min.next = head;
            		min = min.next;
            	}
            	else {
            		max.next = head;
            		max = max.next;
            	}
            	head = head.next;
            }
            max.next = null;
            min.next = lk.next;
            pHead = ret.next;
        }
        return pHead;
    }
    
    public static void main(String[] args) {
    	ListNode[] nodes = new ListNode[5];
    	int[] val = {5, 4, 4, 1, 3};
    	for (int i = 0; i < 5; ++i) {
    		nodes[i] = new ListNode(val[i]);
    		if (i != 0) nodes[i - 1].next = nodes[i];
    	}
    	ListNode head = partition(nodes[0], 5);
    	while (head != null) {
    		System.out.print(head.val + " ");
    		head = head.next;
    	}
    }
}