import java.util.*;

public class Solution {
    public static int getPos(List<Integer> a, int l, int r, int val) {
        int pos = l;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a.get(mid) > val) {
                pos = mid;
                r = r - 1;
            }
            else l = l + 1;
        }
        return pos - 1;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        boolean[] vis = new boolean[1000100];
        long[] sum = new long[1000100];
        int t = in.nextInt();
        List<Integer> prime = new ArrayList<>();
        prime.add(0);
        for (int i = 2; i <= 1000000; ++i) {
            if (!vis[i]) {
                prime.add(i);
                for (int j = i + i; j <= 1000000; j += i) {
                    vis[j] = true;
                }
            }
        }
        for (int i = 1; i < prime.size(); ++i) {
            sum[i] = prime.get(i) + sum[i - 1];
        }
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int pos = getPos(prime, 0, prime.size(), n);
            System.out.println(sum[pos]);
        }
    }
}
