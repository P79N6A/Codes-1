import java.util.ArrayList;

class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}

public class Main {
    
    public static void findPath(TreeNode rt, int sum, int target, ArrayList<Integer> link, ArrayList<ArrayList<Integer>> path) {
        if (rt == null) return;
        link.add(rt.val);
        sum += rt.val;
        if (sum == target && rt.left == null && rt.right == null) {
            path.add(new ArrayList<Integer>(link));
            link.remove(link.size() - 1);
            return;
        }
        findPath(rt.left, sum, target, link, path);
        findPath(rt.right, sum, target, link, path);
        link.remove(link.size() - 1);
    }
    
    public static ArrayList<ArrayList<Integer>> FindPath(TreeNode root,int target) {
        ArrayList<ArrayList<Integer>> path = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> link = new ArrayList<>();
        findPath(root, 0, target, link, path);
        return path;
    }
    
    public static void main(String[] args) {
    	TreeNode node = new TreeNode(1);
    	TreeNode node1 = new TreeNode(2);
    	TreeNode node2 = new TreeNode(1);
    	TreeNode node3 = new TreeNode(1);
    	node.left = node1;
    	node.right = node2;
    	node2.right = node3;
    	System.out.println(FindPath(node, 2));
    }
}