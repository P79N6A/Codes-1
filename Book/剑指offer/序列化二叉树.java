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
    
    int index = -1;
    
    String Serialize(TreeNode root) {
        if (root == null) {
            return "#,";
        }
        StringBuilder sb = new StringBuilder();
        sb.append(root.val).append(",");
        sb.append(Serialize(root.left));
        sb.append(Serialize(root.right));
        return sb.toString();
    }
    
    TreeNode build(String[] str) {
        TreeNode rt = null;
        ++index;
        if (!str[index].equals("#")) {
            rt = new TreeNode(Integer.parseInt(str[index]));
            rt.left = build(str);
            rt.right = build(str);
        }
        return rt;
    }
    
    TreeNode Deserialize(String str) {
        if (str == null) return null;
        index = -1;
        return build(str.split(","));
    }
}