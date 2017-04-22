import java.util.*;

/*
public class UndirectedGraphNode {
    int label = 0;
    UndirectedGraphNode left = null;
    UndirectedGraphNode right = null;
    ArrayList<UndirectedGraphNode> neighbors = new ArrayList<UndirectedGraphNode>();

    public UndirectedGraphNode(int label) {
        this.label = label;
    }
}*/
public class Path {
    public boolean checkPath(UndirectedGraphNode a, UndirectedGraphNode b) {
		return check(a, b) || check(b, a);
	}
    private boolean check(UndirectedGraphNode a, UndirectedGraphNode b) {
        HashMap<UndirectedGraphNode, Boolean> mp = new HashMap<>();
		Queue<UndirectedGraphNode> q = new LinkedList<>();
		q.add(a);
		mp.put(a, true);
		while (!q.isEmpty()) {
			UndirectedGraphNode cur = q.poll();
			if (cur == b) return true;
			for (UndirectedGraphNode x : cur.neighbors) {
				if (mp.containsKey(x)) continue;
				mp.put(x, true);
				q.add(x);
			}
		}
        return false;
    }
}