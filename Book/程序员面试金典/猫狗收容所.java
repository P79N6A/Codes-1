import java.util.*;

public class CatDogAsylum {
    static class Node {
		int id, time;
		public Node(int id, int time) {
			this.id = id;
			this.time = time;
		}
	}
	public static ArrayList<Integer> asylum(int[][] ope) {
        Queue<Node> cat = new LinkedList<>();
        Queue<Node> dog = new LinkedList<>();
        ArrayList<Integer> al = new ArrayList<>();
        for (int i = 0; i < ope.length; ++i) {
        	int op = ope[i][0], id = ope[i][1];
        	//System.out.println(op + " " + id);
        	if (op == 1) {
        		if (id > 0) dog.add(new Node(id, i));
        		else cat.add(new Node(id, i));
        	}
        	else {
        		switch (id) {
        			case 0 :
        				if (cat.isEmpty() && dog.isEmpty()) break;
        				if (cat.isEmpty()) al.add(dog.poll().id);
        				else if (dog.isEmpty()) al.add(cat.poll().id);
        				else {
        					int time1 = cat.peek().time, time2 = dog.peek().time;
        					if (time1 < time2) al.add(cat.poll().id);
        					else al.add(dog.poll().id);
        				}
        				break;
        			case -1 :
        				if (!cat.isEmpty()) al.add(cat.poll().id);
        				break;
        			default:
        				if (!dog.isEmpty()) al.add(dog.poll().id);
        				break;
        		}
        	}
        }
        return al;
    }
}