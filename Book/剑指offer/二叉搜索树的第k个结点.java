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
    
    int cnt;
    
    TreeNode KthNode(TreeNode pRoot, int k)
    {
        cnt = k;
        return find(pRoot);
    }
    
    TreeNode find(TreeNode rt) {
        TreeNode ret = null;
        if (rt != null) {
        	if ((ret = find(rt.left)) != null) return ret;
			if (--cnt == 0) return rt;
        	if ((ret = find(rt.right)) != null) return ret;
        }
        return null;
    }
}