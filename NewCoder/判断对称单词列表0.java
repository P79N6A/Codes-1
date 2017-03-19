import java.util.Scanner;

class Node {
	Node next;
	int val;
	
	public Node(int val) {
		this.val = val;
	}
}

// 空间复杂度O(n), 时间复杂度O(n)
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            String[] s = in.nextLine().split(",");
            // 建立链表
            Node head = new Node(0);
            Node saveH = head;
            for (String ps : s) {
            	head.next = new Node(Integer.parseInt(ps));
            	head = head.next;
            }
            
            head = saveH.next;
            StringBuilder first = new StringBuilder();
            Node pre = null;
            while (head != null) {
            	Node next = head.next;
            	first.append(head.val);
            	head.next = pre;
            	pre = head;
            	head = next;
            }
            StringBuilder second = new StringBuilder();
            while (pre != null) {
            	second.append(pre.val);
            	pre = pre.next;
            }
            if (second.toString().equals(first.toString())) {
            	System.out.println(1);
            }
            else {
            	System.out.println(0);
            }
        }
        in.close();
    }
}