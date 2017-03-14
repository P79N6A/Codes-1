import java.util.ArrayList;
/**
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
    public ArrayList<Integer> PrintFromTopToBottom(TreeNode root) {
        ArrayList<Integer> al = new ArrayList<>();
        if (root == null) return al;
        ArrayList<TreeNode> queue = new ArrayList<>();
        queue.add(root);
        int index = 0;
        while (index < queue.size()) {
            TreeNode cur = queue.get(index++);
            al.add(cur.val);
            if (cur.left != null) {
                queue.add(cur.left);
            }
            if (cur.right != null) {
                queue.add(cur.right);
            }
        }
        return al;
    }
}