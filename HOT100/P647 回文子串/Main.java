package P647;

public class Main {
    // 该题正常暴力的时间复杂度是O(n^3),使用动态规划,会牺牲空间利用状态依赖节省一层循环(判断回文)
    // dp[i][j],表示i-j范围内子字符串是否是回文子串
    public int countSubstrings(String s) {
        int ans = 0;
        boolean[][] dp = new boolean[s.length()][s.length()];

        for(int j = 0;j < s.length();j++){
            for (int i = 0;i <= j;i++){
                // j-i<2 的目的是当子串长度只有2/1时,无法利用状态依赖,相等就+1
                if(s.charAt(i) == s.charAt(j) && (j - i < 2 || dp[i+1][j-1])){
                    ans++;
                    dp[i][j] = true;
                }
            }
        }
        return ans;
    }
    public static void main(String[] args) {
    }
}
