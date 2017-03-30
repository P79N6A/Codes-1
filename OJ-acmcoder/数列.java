import java.util.*;

public class Main {
    
    private static class Pair implements Comparable<Pair>{
        int x, y;

        @Override
        public int compareTo(Pair o2) {
            if (x == o2.x) return o2.y - y;
            return o2.x - x;
        }
    }
    
    private static class Query implements Comparable<Query>{
        int x, y, id;

        @Override
        public int compareTo(Query o2) {
            if (x == o2.x) return o2.y - y;
            return o2.x - x;
        }
    }
    
    private static int mx = 100010;
    private static int[] bit = new int[mx];
    
    private static void add(int pos) {
        for (int i = pos; i < mx; i += i & -i) {
            ++bit[i];
        }
    }
    
    private static int sum(int pos) {
        int ret = 0;
        for (int i = pos; i > 0; i -= i & -i) {
            ret += bit[i];
        }
        return ret;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int q = in.nextInt();
        Pair[] p = new Pair[n];
        
        int[] ans = new int[q];
        Query[] query = new Query[q];
        for (int i = 0; i < n; ++i) {
            p[i] = new Pair();
            p[i].x = in.nextInt();
        }
        for (int i = 0; i < n; ++i) {
            p[i].y = in.nextInt();
        }
        Arrays.sort(p);
        //System.out.println(p[0].x);
        for (int i = 0; i < q; ++i) {
            query[i] = new Query();
            query[i].x = in.nextInt();
            query[i].y = in.nextInt();
            query[i].id = i;
        }
        Arrays.sort(query);
        int pos = 0;
        for (int i = 0; i < q; ++i) {
            while (pos < n && p[pos].x >= query[i].x) {
                add(p[pos].y);
                ++pos;
            }
            int id = query[i].id;
            ans[id] = pos - sum(query[i].y - 1);
        }
        for (int i = 0; i < q; ++i) {
            System.out.println(ans[i]);
        }
        in.close();
    }
}
