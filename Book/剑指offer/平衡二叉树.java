public class Solution {
    
    private boolean is = true;
    
    private int count(TreeNode root, int depth) {
        if (root == null || !is) return depth;
        int left = count(root.left, depth + 1);
        int right = count(root.right, depth + 1);
        if (Math.abs(right - left) > 1) {
            is = false;
        }
        return Math.max(left, right);
    }
    
    public boolean IsBalanced_Solution(TreeNode root) {
    	if (root == null) return is;
        int left = count(root.left, 0);
        int right = count(root.right, 0);
        if (Math.abs(right - left) > 1) {
            is = false;
        }
        return is;
    }
}