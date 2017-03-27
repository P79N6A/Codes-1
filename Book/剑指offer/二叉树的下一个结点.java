/*
public class TreeLinkNode {
    int val;
    TreeLinkNode left = null;
    TreeLinkNode right = null;
    TreeLinkNode next = null;

    TreeLinkNode(int val) {
        this.val = val;
    }
}
*/
public class Solution {
    
    public TreeLinkNode getLeft(TreeLinkNode rt) {
        if (rt.left == null) return rt;
        return getLeft(rt.left);
    }
    
    public TreeLinkNode getPar(TreeLinkNode chd, TreeLinkNode rt) {
        if (rt == null) return null;
        if (rt.left == chd) return rt;
        return getPar(rt, rt.next);
    }
    
    public TreeLinkNode GetNext(TreeLinkNode pNode) {
        if (pNode == null) return null;
        if (pNode.right == null) return getPar(pNode, pNode.next);
        else {
            return getLeft(pNode.right);
        }
    }
}