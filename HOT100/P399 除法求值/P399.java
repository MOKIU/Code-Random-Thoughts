package P399除法求值;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class P399 {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        int equationSize = equations.size();
        // 并查集确保有关联的数组都是连通的
        // 为什么乘2是因为,节点有两个方向
        UnionFind unionFind = new UnionFind(2 * equationSize);
        // 存储节点字符串,和对应的节点id
        Map<String, Integer> hashmap = new HashMap<>(2 * equationSize);
        int id = 0;
        // 预处理,将起始连接的节点放入到并查集中
        for (int i = 0; i < equationSize; i++) {
            String str1 = equations.get(i).get(0);
            String str2 = equations.get(i).get(1);

            if(!hashmap.containsKey(str1)){
                hashmap.put(str1, id);
                id++;
            }
            if(!hashmap.containsKey(str2)){
                hashmap.put(str2, id);
                id++;
            }

            unionFind.union(hashmap.get(str1), hashmap.get(str2), values[i]);
        }

        // 查询
        double[] res = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            String str1 = queries.get(i).get(0);
            String str2 = queries.get(i).get(1);

            Integer id1 = hashmap.get(str1);
            Integer id2 = hashmap.get(str2);

            // int不能判断null,但Integer就可以判断null
            // 为空代表字符串不在提供的方程组里
            if(id1 == null || id2 == null){
                res[i] = -1.0d;
            }else{
                // 查找结果
                res[i] = unionFind.isConnected(id1, id2);
            }
        }
        return res;
    }
    private class UnionFind{
        // 父节点数组,有向图中的被指方
        private int[] parent;
        // 指向父节点的权值,代表对应除法的大小,本节点/父节点
        private double[] weight;
        // 构造函数
        public UnionFind(int n){
            this.parent = new int[n];
            this.weight = new double[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                weight[i] = 1.0d; // 开始默认自己/自己为1
            }
        }
        // x,y是x/y的关系
        public void union(int x, int y, double value){
            // 找x的根节点
            int rootX = find(x);
            // 找y的根节点
            int rootY = find(y);
            // 两个根节点相同,代表开始他们是并列关系的,不是除和被除关系,互相无关联,不用管
            if(rootX == rootY){
                return;
            }

            // 让x的根节点的父节点指向y的父节点
            parent[rootX] = rootY;
            // weight[y] = y / rootY
            // weight[x] = x / rootX
            // value = x / y
            weight[rootX] = weight[y] * value / weight[x];
        }

        // 找到本节点的父节点,在寻找的过程中,进行路径压缩
        public int find(int x){
            // 父节点不是自己情况下,即没遍历到根节点,计算weight[x]的权重
            if (x != parent[x]){
                int origin = parent[x];
                // 找到根节点,进行路径压缩
                parent[x] = find(parent[x]);
                weight[x] *= weight[origin];
            }
            return parent[x];
        }

        // 此时给出的所有equation都形成路径压缩后的有向图了,所以借助并查集可以实现O(1)复杂度的查找
        public double isConnected(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX == rootY){
                return weight[x] / weight[y];
            }else{
                // 之间没有连通,计算不出来
                return -1.0d;
            }
        }
    }
    public static void main(String[] args) {

    }
}
