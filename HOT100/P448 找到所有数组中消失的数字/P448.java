package P448找到所有数组中消失的数字;

import java.util.*;

public class P448 {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        // 原地修改
        for(int num : nums){
            // 利用nums[i]都在1~n内的条件,如果超过就不行了
            // 如果num是在1~n内,求余结果和下标和num一一对应
            int x = (num - 1) % n;
            // 简单来说就是让存在的数对应下标对应的数呈现统一状态
            if(nums[x] <= n){
                nums[x] += n;
            }
        }
        List<Integer> ret = new ArrayList<Integer>();
        // 不存在的数对应的下标就还是num[i]还在i~n范围内
        for (int i = 0; i < n; i++) {
            if(nums[i] <= n){
                ret.add(i + 1);
            }
        }
        return ret;
//        List<Integer> ans = new ArrayList<Integer>(nums.length + 1);
//        for (int i = 0; i <= nums.length; i++) {
//            ans.add(1);  // 手动填充1
//        }
//        // 将num[i]作为下标,将对应ans数值置0
//        for (int i = 0; i < nums.length; i++) {
//            if(nums[i] >= 1 && nums[i] <= nums.length){
//                ans.set(nums[i], 0);
//            }
//        }
//        // 不是0的值就是不存在的数,设置对应下标的数据
//        for (int i = 1; i <= nums.length; i++) {
//            if(ans.get(i) != 0){
//                ans.set(i, i);
//            }
//        }
//        ans.remove(0);
//        ans.removeIf(n -> n == 0);
//        return ans;
    }
    public static void main(String[] args) {

    }
}
