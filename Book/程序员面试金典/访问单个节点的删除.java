import java.util.*;

/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Remove {
    public boolean removeNode(ListNode pNode) {
        if (pNode == null || pNode.next == null) return false;
        pNode = pNode.next;
        return true;
    }
}