import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
/**
 * 注意数组值范围只到1e7
 * 所以考虑存下所有范围内素数
 * 然后对每个素数,统计它倍数的和,类似素数筛
 * 最后二分一下下标,done
 * 注意Java用Scanner会T
 * @author GooZy
 */

public class Main {
    
    private static final int MAXN = (int)(1e7 + 10);
    private static int[] times = new int[MAXN];
    private static boolean[] is = new boolean[MAXN];
    
    public static void main(String[] args) throws IOException {
        try (BufferedReader in = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(in.readLine());
            String[] str = in.readLine().split(" ");
            for (int i = 0; i < n; ++i) {
                ++times[Integer.parseInt(str[i])];
            }
            int m = Integer.parseInt(in.readLine());
            ArrayList<Integer> prim = new ArrayList<>();
            prim.add(0);
            for (int i = 2; i < MAXN; ++i) {
                if (!is[i]) {
                    prim.add(i);
                    for (int j = i + i; j < MAXN; j += i) is[j] = true;
                }
            }
            
            int[] num = new int[prim.size()];
            for (int i = 1; i < prim.size(); ++i) {
                int x = prim.get(i);
                num[i] += num[i - 1];
                for (int j = x; j < MAXN; j += x) {
                    num[i] += times[j];
                }
            }
            prim.add((int)1e7 + 9);
            
            PrintWriter pr = new PrintWriter(new OutputStreamWriter(System.out));
            for (int i = 0; i < m; ++i) {
                str = in.readLine().split(" ");
                int l = getpos(prim, Integer.parseInt(str[0]));
                int rr = Math.min(Integer.parseInt(str[1]), (int)1e7);
                int r = getpos(prim, rr);
                if (prim.get(r) > rr) r -= 1;
                //System.out.println(l + "     " + r);
                pr.println(num[r] - num[l - 1]);
            }
            pr.close();
        }
    }
    
    private static int getpos(ArrayList<Integer> al, int target) {
        int l = 1, r = al.size() - 1;
        int ret = r;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (al.get(mid) < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
                ret = mid;
            }
        }
        return ret;
    }
}