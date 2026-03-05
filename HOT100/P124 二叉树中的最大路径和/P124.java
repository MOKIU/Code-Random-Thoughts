package P124二叉树中的最大路径和;

class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(){}
    TreeNode(int val, TreeNode left, TreeNode right){
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
public class P124 {
    int curMax;
    // 后序遍历
    void traversal(TreeNode cur){
        if(cur == null)return;
        traversal(cur.left);
        traversal(cur.right);
        // 如果是叶子节点,,路径和为自己值
        if(cur.left == null && cur.right == null){
            this.curMax = Math.max(curMax, cur.val);
        }else{
            // 如果是非叶子节点
            int tmp = cur.val;
            if(cur.left != null && cur.left.val > 0){
                tmp += cur.left.val;
            }
            if(cur.right != null && cur.right.val > 0){
                tmp += cur.right.val;
            }
            this.curMax = Math.max(curMax, tmp);

            // 比较完将自己节点值更新为加上>0且大的孩子节点,因为只能选一个孩子作为后续的路径
            if(cur.left != null && cur.right == null && cur.left.val > 0){
                cur.val += cur.left.val;
            }else if(cur.right != null && cur.left == null && cur.right.val > 0){
                cur.val += cur.right.val;
            }else if(cur.right != null && cur.left != null){
                int tmp1 = cur.left.val;
                int tmp2 = cur.right.val;
                int childMax = Math.max(tmp1, tmp2);
                cur.val += Math.max(childMax, 0);
            }
        }
    }
    public int maxPathSum(TreeNode root){
        this.curMax = root.val;
        traversal(root);
        return this.curMax;
    }
    public static void main(String[] args) {

    }
}
