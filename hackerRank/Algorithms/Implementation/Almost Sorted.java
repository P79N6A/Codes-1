import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        
        if (isAsc(a, 0, n - 1)) {
            System.out.println("yes");
            return;
        }
        
        int bg = -1, ed = n;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                bg = i - 1;
                break;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] > a[i + 1]) {
                ed = i + 1;
                break;
            }
        }
        
        swap(a, bg, ed);
        if (isAsc(a, 0, n - 1)) {
            System.out.println("yes");
            System.out.printf("swap %d %d\n", bg + 1, ed + 1);
            return;
        }
        for (int i = bg + 1; ; ++i) {
            int j = ed - (i - bg);
            if (j <= i) break;
            swap(a, i, j);
        }
        if (isAsc(a, 0, n - 1)) {
            System.out.println("yes");
            System.out.printf("reverse %d %d\n", bg + 1, ed + 1);
        }
        else System.out.println("no");
    }
    
    public static boolean isAsc(int[] a, int bg, int ed) {
        for (int i = bg + 1; i <= ed; ++i) {
            if (a[i] < a[i - 1]) return false;
        }
        return true;
    }
    
    public static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}