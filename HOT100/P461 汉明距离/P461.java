package P461汉明距离;

public class P461 {
    public int hammingDistance(int x, int y){
        // 使用内置位计数功能,异或操作
//        return Integer.bitCount(x ^ y);

        // Brian Kernighan 算法
        int s = x ^ y, ret = 0;
        // 统计s有多少个1,只找1
        while (s != 0){
            s &= s-1; // 该操作会从后往前消除第一个1
            ret++;
        }
        return ret;

//        int ans = 0;
        // 使用API
//        String str1 = String.format("%32s", Integer.toBinaryString(x)).replace(' ', '0');
//        String str2 = String.format("%32s", Integer.toBinaryString(y)).replace(' ', '0');

        // 手动转换二进制
        // 想像十进制对应的二进制数,/2就相当于右移一位,类似十进制求各个位数
//        StringBuilder sb1 = new StringBuilder();
//        StringBuilder sb2 = new StringBuilder();
//        while(x > 0){
//            sb1.insert(0, x % 2);
//            x /= 2;
//        }
//        while (y > 0){
//            sb2.insert(0, y % 2);
//            y /= 2;
//        }
//
//        String str1 = String.format("%32s", sb1.toString()).replace(' ', '0');
//        String str2 = String.format("%32s", sb2.toString()).replace(' ', '0');
//
//        for(int i = 0;i < 32;i++){
//            if (str1.charAt(i) != str2.charAt(i)){
//                ans++;
//            }
//        }

//        return ans;
    }
    public static void main(String[] args) {

    }
}
