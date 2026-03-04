package P128最长连续序列;

import java.util.HashSet;
import java.util.Set;

public class P128 {
    public int longestConsecutive(int[] nums) {
        // 拿哈希表确实比较巧妙,遍历连续序列是否在数组中,而不是遍历数组中是否存在连续序列
        Set<Integer> num_set = new HashSet<>();
        for(int num : nums){
            num_set.add(num);
        }

        int longestStreak = 0;

        for (int num : num_set){
            // 能保证总时间复杂度是O(1),主要是因为set.contain()方法的平均复杂度为O(1),根据计算的哈希查找
            // 找最长序列的起点,也就是没有比他小一个的连续数,只从起点开始找,不从中间开始找
            // for循环内部有一个while循环却不是O(n)的原因是,如果他不能作为起点就不考虑了,剪枝,所以每个元素只遍历一次
            if(!num_set.contains(num - 1)){
                int currentNum = num;
                int currentStreak = 1;

                while(num_set.contains(currentNum + 1)){
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
    public static void main(String[] args) {

    }
}
