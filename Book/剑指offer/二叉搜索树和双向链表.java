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
    
    private TreeNode temp = null, ans = null;
    
    public void convert(TreeNode rt) {
        if (rt == null) return;
        Convert(rt.left);
        if (temp == null) {
            temp = rt;
            ans = rt;
        }
        else {
            temp.right = rt;
            rt.left = temp;
            temp = rt;
        }
        Convert(rt.right);
    }
    
    public TreeNode Convert(TreeNode rt) {
        convert(rt);
        return ans;
    }
}