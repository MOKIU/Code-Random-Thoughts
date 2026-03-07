package P438找到字符串中所有字母异位词;

import java.util.ArrayList;
import java.util.List;

public class P438 {
//    // 本题利用异位词字母无序且只存在一个的特点,本着空间换时间的想法集合字母数组的特性[0-25],考虑的数据结构由数组->队列->栈->数组
//    // 字母数组存储p各个字母的个数,不在p的字母是0,方便后续出现的话减-1出现-1就重置
//    int[] alpha = new int[26];
//    int[] basic = new int[26]; // p对应字符数字数组
//    // 初始化数组
//    public void initArr(int[] arr,String p){
//        for (int i = 0; i < 26; i++) {
//            arr[i] = 0;
//        }
//        for (int i = 0; i < p.length(); i++) {
//            arr[p.charAt(i) - 'a']++;
//        }
//    }
//    public List<Integer> findAnagrams(String s, String p) {
//        int startIndex = 0;
//        List<Integer> ans = new ArrayList<>();
//        int len = p.length();
//        // 初始化
//        initArr(this.alpha, p);
//        initArr(this.basic, p);
//
//        for (int i = 0; i < s.length(); i++) {
//            // startIndex是用在s上的,不是用在alpha上的这个要注意
//            int curIndex = s.charAt(i) - 'a';
//            int alphaIndex = s.charAt(startIndex) - 'a';
//            if(--this.alpha[curIndex] == -1){
//                // 减多了,如果减多的这个和startIndex字符一致的话,就只恢复这一个位置(下一轮要把startIndex字符抛弃)
//                if(s.charAt(startIndex) == s.charAt(i)){
//                    this.alpha[curIndex]++;
//                    // 更新起始点到下个字符
//                    startIndex++;
//                } else if (this.basic[curIndex] != 0){
//                    // 减多了,减的字符与要去除的字符不一致,且是存在与p的字符
//                    // 说明目前减的字符出现在startIndex~curIndex-1之间了,startIndex要跳到第一个重复字符的后一位重新开始
//                    while(s.charAt(startIndex) != s.charAt(i)){
//                        this.alpha[s.charAt(startIndex) - 'a']++;
//                        startIndex++;
//                    }
//                    this.alpha[curIndex]++;
//                    startIndex++;
//                }else{
//                    // 目前的字符根本不存在于p,直接跳过,重置alpha
//                    startIndex = i + 1;
//                    initArr(this.alpha, p);
//                }
//            }
//            // 减了len个1都没出现-1(startIndex没更新),说明数组正好都减为0了,结果是对的
//            if (i - startIndex + 1 == len) {
//                ans.add(startIndex);
//                // 不重置元素重新来,i已经走过的元素状态保存在alpha就可以了,因为startIndex要后移,只需要将startIndex位置元素恢复即可
//                this.alpha[alphaIndex]++;
//                startIndex++;
//            }
//        }
//        return ans;
//    }

    // 本题利用异位词字母无序且只存在一个的特点,本着空间换时间的想法集合字母数组的特性[0-25],考虑的数据结构由数组->队列->栈->数组
    // 字母数组存储p各个字母的个数,不在p的字母是0,方便后续出现的话减-1出现-1就重置
    int[] alpha = new int[26];

    // 初始化数组
    public void initArr(int[] arr, String p) {
        for (int i = 0; i < 26; i++)
            arr[i] = 0;
        for (int i = 0; i < p.length(); i++) {
            arr[p.charAt(i) - 'a']++;
        }
    }

    public List<Integer> findAnagrams(String s, String p) {
        int startIndex = 0;
        List<Integer> ans = new ArrayList<>();
        int len = p.length();
        initArr(alpha, p);

        for (int i = 0; i < s.length(); i++) {
            int curIndex = s.charAt(i) - 'a';

            alpha[curIndex]--; // 需求减少

            // 如果某个字符多了，移动 startIndex 直到它恢复
            while (alpha[curIndex] < 0) {
                int startCharIndex = s.charAt(startIndex) - 'a';
                alpha[startCharIndex]++;
                startIndex++;
            }

            // 窗口长度正好为 len，说明是异位词
            if (i - startIndex + 1 == len) {
                ans.add(startIndex);
                // 移除最左边字符，为下一轮准备
                int startCharIndex = s.charAt(startIndex) - 'a';
                alpha[startCharIndex]++;
                startIndex++;
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        String s = "abacbabc";
        String p = "abc";
        P438 question = new P438();
        List<Integer> ans = question.findAnagrams(s, p);
        System.out.println(ans);
    }
}
