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
    int ans = 0;
    public void getDepth(TreeNode root, int len) {
        if (root == null) {
            ans = Math.max(ans, len);
            return;
        }
        getDepth(root.left, len + 1);
        getDepth(root.right, len + 1);
    }
    
    public int TreeDepth(TreeNode root) {
        getDepth(root, 0);
        return ans;
    }
}