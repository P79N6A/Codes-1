/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
 //最后出现的点，最先放入。over
public class Solution {
    TreeNode save;
    public void flatten(TreeNode root) {
        if (root == null) return;
        flatten(root.right);
        flatten(root.left);
        root.right = save;
        root.left = null;
        save = root;
    }
}