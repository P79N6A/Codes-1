import java.util.*;
/**
 * 需要找前缀,后缀相同,且存在于中间的。
 * KMP算法的Next数组非常符合。
 * nxt[n]是第一个可行,接着是nxt[nxt[n]]
 * 每一次On遍历查找是否有nxt值相同的中间。
 * @author GooZy
 */

public class Main {
    
    private static final int MAXN = 110;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        char[] s = in.next().toCharArray();
        int[] nxt = new int[s.length + 1];
        nxt[0] = -1;
        for (int i = 0; i < s.length; ++i) {
            int k = nxt[i];
            while (k != -1 && s[i] != s[k]) k = nxt[k];
            nxt[i + 1] = ++k;
        }
        int ans = nxt[s.length];
        while (ans != 0) {
            for (int i = 0; i < s.length; ++i) {
                if (nxt[i] == ans) {
                    System.out.println(new String(s).substring(0, ans));
                    return;
                }
            }
            ans = nxt[ans];
        }
        System.out.println("Just a legend");
        in.close();
    }
}