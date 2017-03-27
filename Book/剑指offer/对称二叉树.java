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
import java.util.ArrayList;
public class Solution {
    
    ArrayList<Integer> al = new ArrayList<>(), alv = new ArrayList<>();
    ArrayList<Integer> ar = new ArrayList<>(), arv = new ArrayList<>();
    
    void firstOrder(TreeNode rt, int val) {
        if (rt == null) return;
        al.add(val);
        alv.add(rt.val);
        firstOrder(rt.left, 0);
        firstOrder(rt.right, 1);
    }
    
    void lastOrder(TreeNode rt, int val) {
        if (rt == null) return;
        ar.add(val);
        arv.add(rt.val);
        lastOrder(rt.right, 1);
        lastOrder(rt.left, 0);
    }
    
    boolean isSymmetrical(TreeNode pRoot)
    {
        if (pRoot == null) return true;
        firstOrder(pRoot, 0);
        lastOrder(pRoot, 1);
        for (int i = 0; i < al.size(); ++i) {
            if (al.get(i) == ar.get(i)) return false;
        }
        return alv.toString().equals(arv.toString());
    }
}

// 可以直接递归判断：judge(rt.left, rt.right)