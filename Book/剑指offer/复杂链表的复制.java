class RandomListNode {
    int label;
    RandomListNode next = null;
    RandomListNode random = null;

    RandomListNode(int label) {
        this.label = label;
    }
}

public class Solution {
    public static RandomListNode Clone(RandomListNode pHead) {
        if (pHead == null) 
        	return null;
        RandomListNode cur = pHead;
        while (cur != null) {
        	RandomListNode nw = new RandomListNode(cur.label);
        	nw.next = cur.next;
        	cur.next = nw;
        	cur = nw.next;
        }
        cur = pHead;
        while (cur != null) {
        	RandomListNode nxt = cur.next;
        	if (cur.random != null)
        		nxt.random = cur.random.next;
        	cur = cur.next.next;
        }
        cur = pHead;
        while (cur != null) {
        	RandomListNode nxt = cur.next;
        	RandomListNode nxtNode = nxt.next;
        	if (nxtNode != null)
        		nxt.next = nxtNode.next;
        	cur.next = nxtNode;
        	cur = nxtNode;
        }
        return pHead.next;
    }
	public static void main(String[] args) {
		RandomListNode node1 = new RandomListNode(1);
		RandomListNode node2 = new RandomListNode(2);
		RandomListNode node3 = new RandomListNode(3);
		node1.next = node2;
		node2.next = node3;
		node3.random = node1;
		node1.random = node2;
		node2.random = node1;
		RandomListNode node = Clone(node1);
		System.out.println(node.next.random.label);
	}
}