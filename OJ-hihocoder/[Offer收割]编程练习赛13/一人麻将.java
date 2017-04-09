import java.util.*;

public class Main {
    
    private static final long INF = (long)1e16;
    private static int[][] num = new int[3][10];
    
    private static void add(char[] s) {
        ++num[s[0] - 'a'][s[1] - '0'];
    }
    
    private static int count(int x) {
        int cnt1 = 0;
        int[] temp = new int[10];
        for (int i = 1; i <= 9; ++i) temp[i] = num[x][i];
        for (int i = 1; i <= 7; ++i) {
            int cur = Math.min(Math.min(temp[i], temp[i + 1]), temp[i + 2]);
            cnt1 += cur;
            for (int j = 0; j < 3; ++j) {
                temp[i + j] -= cur;
            }
        }
        for (int i = 1; i <= 9; ++i) cnt1 += temp[i] / 3;
        
        int cnt2 = 0;
        for (int i = 1; i <= 9; ++i) temp[i] = num[x][i];
        for (int i = 1; i <= 9; ++i) {
            cnt2 += temp[i] / 3;
            temp[i] %= 3;
        }
        for (int i = 1; i <= 7; ++i) {
            int cur = Math.min(Math.min(temp[i], temp[i + 1]), temp[i + 2]);
            cnt2 += cur;
            for (int j = 0; j < 3; ++j) {
                temp[i + j] -= cur;
            }
        }
        return Math.max(cnt1, cnt2);
    }
    
    private static boolean ok() {
        for (int i = 0; i < 3; ++i) {
            int cnt = 0;
            int x = i, y = (x + 1) % 3;
            for (int j = 1; j <= 9; ++j) {
                cnt += num[x][j] / 2 + num[y][j] / 2;
            }
            if (cnt >= 7) return true;
            
            for (int j = 1; j <= 9; ++j) {
                if (num[x][j] > 1) {
                    num[x][j] -= 2;
                    if (count(x) + count(y) > 3) return true;
                    num[x][j] += 2;
                }
                if (num[y][j] > 1) {
                    num[y][j] -= 2;
                    if (count(x) + count(y) > 3) return true;
                    num[y][j] += 2;
                }
            }
        }
        return false;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int ans = -1;
        for (int i = 0; i < 14; ++i) {
            add(in.next().toCharArray());
        }
        if (ok()) ans = 0;
        for (int i = 0; i < n; ++i) {
            add(in.next().toCharArray());
            if (ans == -1 && ok()) {
                ans = i + 1;
            }
        }
        System.out.println(ans);
        in.close();
    }
}