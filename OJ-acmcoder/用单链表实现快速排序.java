import java.util.*;

public class Main {


/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
	//3,6,10,7,9,8,1,2,11,17,15,13,12
/******************************开始写代码******************************/
	static void quickSort(Node head, Node tail) {
		if (head == tail) return;
		int key = head.data;
		Node i = head;
		Node j = head.next;
		while (j != tail) {
			if (j.data < key) {
				i = i.next;
				swap(i, j);
			}
			j = j.next;
		}
		swap(i, head);
		quickSort(head, i);
		quickSort(i.next, tail);
	}
	
	static void swap(Node x, Node y) {
		int temp = x.data;
		x.data = y.data;
		y.data = temp;
	}
	
    static String quickSortInputOutput(String str) {
    	String[] num = str.split(",");
    	if (num.length == 1) return str;
    	Node[] nodes = new Node[num.length];
    	for (int i = num.length - 1; i >= 0; --i) {
    		if (i == num.length - 1) {
    			nodes[i] = new Node(Integer.parseInt(num[i]), null);
    		}
    		else nodes[i] = new Node(Integer.parseInt(num[i]), nodes[i + 1]);
    	}
    	LinkList ll = new LinkList(nodes[0], nodes[num.length - 1]);
    	quickSort(ll.head, null);
    	StringBuilder sb = new StringBuilder();
    	Node rt = ll.head;
    	while (rt.next != null) {
    		sb.append(String.valueOf(rt.data) + ",");
    		rt = rt.next;
    	}
    	sb.append(String.valueOf(rt.data));
    	return sb.toString();
    }
/******************************结束写代码******************************/


    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        String res;
            
        String _str;
        try {
            _str = in.nextLine();
        } catch (Exception e) {
            _str = null;
        }
  
        res = quickSortInputOutput(_str);
        System.out.println(res);
    }
}

class Node {
    public int data;
    public Node next;

    public Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }
}

class LinkList {
    public Node head;
    public Node tail;

    public LinkList(Node head, Node tail) {
        this.head = head;
        this.tail = tail;
    }

}
