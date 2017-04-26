import java.util.*;

/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;
    public TreeNode(int val) {
        this.val = val;
    }
}*/
public class Checker {
    public boolean checkBST(TreeNode root) {
        if (root == null) return false;
        if (root.left != null) {
            if (root.left.val > root.val) return false;
            if (!check(root.left, root, true)) return false;
        }
        if (root.right != null) {
            if (root.right.val < root.val) return false;
            if (!check(root.right, root, false)) return false;
        }
        return true;
    }
    
    private boolean check(TreeNode root, TreeNode par, boolean ck) {
        if (root.left != null) {
            if (root.left.val > root.val) return false;
            if (!check(root.left, root, true)) return false;
        }
        if (root.right != null) {
            if (root.right.val < root.val || (ck && root.right.val > par.val)) return false;
            if (!check(root.right, root, false)) return false;
        }
        return true;
    }
}