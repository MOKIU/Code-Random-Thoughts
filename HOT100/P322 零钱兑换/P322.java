package P322零钱兑换;

import java.util.Arrays;

public class P322 {
    // dp[j]表示容量为j时,能正好装满最少需要多少硬币
    public int coinChange(int[] coins, int amount) {
        int max = Integer.MAX_VALUE;
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, max);
        // 先遍历钱币,是不是顺序的都一样,求最小值
        dp[0] = 0;
        for (int i = 0; i < coins.length; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                // 减去这个钱币值剩下的容量对应dp值为max,表示这是不能被目前所拥有的钱币兑换的
                if(dp[j - coins[i]] != max){
                    dp[j] = Math.min(dp[j - coins[i]] + 1, dp[j]);
                }
            }
        }
        return dp[amount] == max ? -1 : dp[amount];
    }
    public static void main(String[] args) {

    }
}
