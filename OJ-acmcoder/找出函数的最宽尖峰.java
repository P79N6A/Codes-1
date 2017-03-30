import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        int[] l = new int[n];
        int[] r = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        r[n - 1] = 0;
        int cnt = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] > a[i + 1]) {
                r[i] = ++cnt;
            }
            else {
                r[i] = 0;
                cnt = 0;
            }
        }
        int mx = -1, ansl = -1, ansr = -1;
        l[0] = 0;
        cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] > a[i - 1]) {
                l[i] = ++cnt;
                if (r[i] != 0 && l[i] + r[i] > mx) {
                    mx = l[i] + r[i];
                    ansl = i - l[i];
                    ansr = i + r[i];
                }
            }
            else cnt = 0;
        }
        System.out.println(ansl + " " + ansr);
        in.close();
    }
}
