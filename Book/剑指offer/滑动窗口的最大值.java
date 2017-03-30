import java.util.*;

class Node {
    int val;
    int pos;
    public Node(int pos, int val) {
        this.pos = pos;
        this.val = val;
    }
}

public class Solution {
    public ArrayList<Integer> maxInWindows(int [] num, int size) {
        ArrayList<Integer> ret = new ArrayList<>();
        LinkedList<Node> dq = new LinkedList<>();
        if (num == null || size == 0 || num.length < size) return ret;
        for (int i = 0; i < size; ++i) {
            if (dq.isEmpty()) dq.add(new Node(i, num[i]));
            else {
                if (num[i] > dq.peekLast().val) dq.add(new Node(i, num[i]));
                else {
                    while (dq.peekFirst().val < num[i]) {
                        dq.pollFirst();
                    }
                    dq.addFirst(new Node(i, num[i]));
                }
            }
        }
        ret.add(dq.peekLast().val);
        for (int i = size; i < num.length; ++i) {
            int last = i - size;
            if (dq.isEmpty()) dq.add(new Node(i, num[i]));
            else {
                if (num[i] > dq.peekLast().val) dq.add(new Node(i, num[i]));
                else {
                    while (dq.peekFirst().val < num[i]) {
                        dq.pollFirst();
                    }
                    dq.addFirst(new Node(i, num[i]));
                }
            }
            while (dq.peekLast().pos <= last) dq.pollLast();
            ret.add(dq.peekLast().val);
        }
        return ret;
    }
}