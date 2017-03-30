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
    public boolean HasSubtree(TreeNode root1,TreeNode root2) {
        if (root2 == null || root1 == null) return false;
        boolean ret = false;
        if (root1.val == root2.val) {
            boolean flag1 = false, flag2 = false;
            if (root2.left == null || HasSubtree(root1.left, root2.left)) {
                 flag1 = true;
            }
            if (root2.right == null || HasSubtree(root1.right, root2.right)) {
                 flag2 = true;
            }
            ret = flag1 & flag2;
        }
        if (ret) return ret;
        if (HasSubtree(root1.left, root2) || HasSubtree(root1.right, root2)) {
            return true;
        }
        return false;
    }
}