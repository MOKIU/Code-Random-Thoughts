package P437路径总和3;

import java.util.HashMap;
import java.util.Map;

public class P437 {
    class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(){}
        TreeNode(int val){this.val = val;}
        TreeNode(int val, TreeNode left, TreeNode right){
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    public int pathSum(TreeNode root, int targetSum) {
        // key:前缀和,value为该前缀和出现的次数
        Map<Long, Integer> prefix = new HashMap<Long, Integer>();
        // 初始化:空路径的前缀和为0,出现次数为1
        prefix.put(0L, 1);
        return dfs(root, prefix, 0, targetSum);
    }
    public int dfs(TreeNode root, Map<Long, Integer> prefix, long curr, int targetSum){
        if(root == null){
            return 0;
        }
        // 加上该节点出现的结果数量
        int ret = 0;
        // 加上当前节点更新前缀和
        curr += root.val;

        // 解题的核心: 当前前缀和 - 目标值 = 需要查找的历史前缀和,没有默认返回0
        // 如果有,说明从历史前缀和那个节点往下(开区间)到本节点这一路径是符合条件的答案,有几个符合条件的历史前缀和就有几条路径
        ret = prefix.getOrDefault(curr - targetSum, 0);
        // 把当前前缀和放进前缀和映射表,没有为0,有则加1
        prefix.put(curr, prefix.getOrDefault(curr, 0) + 1);
        // 往左子树遍历
        ret += dfs(root.left, prefix, curr, targetSum);
        // 往右子树遍历
        ret += dfs(root.right, prefix, curr, targetSum);
        // 回溯,自己这个前缀和没用了,把自己从映射表剔除掉
        prefix.put(curr, prefix.getOrDefault(curr, 0) - 1);

        return ret;
    }
    public static void main(String[] args) {

    }
}
