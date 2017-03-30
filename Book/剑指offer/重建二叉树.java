/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
	public TreeNode getTree(int[] pre, int bg, int ed, int[] in, int bg2, int ed2) {
		TreeNode ret = new TreeNode(pre[bg]);
		if (bg == ed) return ret;
        int cnt = 0;
		for (int i = bg2; i <= ed2; ++i) {
			if (pre[bg] == in[i]) {
				if (i - 1 >= bg2) {
					ret.left = getTree(pre, bg + 1, bg + cnt, in, bg2, i - 1);
				}
				if (i + 1 <= ed2) {
					ret.right = getTree(pre, bg + cnt + 1, ed, in, i + 1, ed2);
				}
				break;
			}
            ++cnt;
		}
		return ret;
	}
	
    public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
    	if (pre.length == 0) return null;
        return getTree(pre, 0, pre.length - 1, in, 0, in.length - 1);
    }
}

// More elegant solution
import java.util.Arrays;

public class Solution {
    public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
    	if (pre.length == 0 || in.length == 0) return null;
    	TreeNode node = new TreeNode(pre[0]);
    	for (int i = 0; i < in.length; ++i) {
    		if (pre[0] == in[i]) {
    			node.left = reConstructBinaryTree(Arrays.copyOfRange(pre, 1, i + 1), Arrays.copyOfRange(in, 0, i));
    			node.right = reConstructBinaryTree(Arrays.copyOfRange(pre, i + 1, pre.length), Arrays.copyOfRange(in, i + 1, in.length));
    		}
    	}
    	return node;
    }
}