import java.util.*;

/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    public ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer> > ans = new ArrayList<>();
        LinkedList<Integer> line = new LinkedList<>();
        if (pRoot == null) return ans;
        
        LinkedList<TreeNode> stack = new LinkedList<>(), stack2 = new LinkedList<>();
        stack.add(pRoot);
        
        boolean left = false;
        while (!stack.isEmpty() || !stack2.isEmpty()) {
            if (stack.isEmpty()) {
                stack = new LinkedList<>(stack2);
                stack2.clear();
                left = !left;
                ans.add(new ArrayList<>(line));
                line.clear();
            }
            TreeNode cur = stack.pop();
            //System.out.println(cur.val);
            line.addFirst(cur.val);
            if (left) {
                if (cur.left != null) {
                    stack2.addFirst(cur.left);
                }
                if (cur.right != null) {
                    stack2.addFirst(cur.right);
                }
            }
            else {
                if (cur.right != null) {
                    stack2.addFirst(cur.right);
                }
                if (cur.left != null) {
                    stack2.addFirst(cur.left);
                }
            }
        }
        if (!line.isEmpty()) ans.add(new ArrayList<>(line));
        return ans;
    }

}