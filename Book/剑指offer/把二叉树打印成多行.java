import java.util.ArrayList;


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
    ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer> > ans = new ArrayList<>();
        if (pRoot == null) return ans;
        ArrayList<TreeNode> al = new ArrayList<>();
        al.add(pRoot);
        int last = 0;
        while (true) {
            int mx = al.size();
            if (last == mx) break;
            ArrayList<Integer> add = new ArrayList<>();
            for (int i = last; i < mx; ++i) {
                TreeNode cur = al.get(i);
                add.add(cur.val);
                if (cur.left != null) al.add(cur.left);
                if (cur.right != null) al.add(cur.right);
            }
            ans.add(add);
            last = mx;
        }
        return ans;
    }
}