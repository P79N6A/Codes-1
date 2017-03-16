import java.util.*;

public class Main {
    public static ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
        ArrayList<Integer> ans = new ArrayList<>();
        if (k > input.length) return ans;
        qsort(0, input.length - 1, input, k);
        k = Math.min(k, input.length);
        for (int i = 0; i < k; ++i) ans.add(input[i]);
        return ans;
    }
    
    private static void qsort(int st, int ed, int[] a, int k) {
        if (st >= k || st >= ed) return;
        int povit = (ed - st) / 2 + st;
        swap(a, povit, ed);
//        System.out.println(a[ed]);
        int l = st, r = ed;
//        System.out.println(l + " " + r);
        do {
            while (l < ed && a[l] < a[ed]) ++l;
            while (r > l && a[r] >= a[ed]) --r;
            swap(a, l, r);
        } while (l < r);
//        System.out.println(l + " " + r);
//        System.out.println(a[ed]);
        swap(a, l, ed);
//        for (int i = st; i <= ed; ++i) {
//        	System.out.print(a[i]+" ");
//        }
//        System.out.println("==========");
        qsort(st, l - 1, a, k);
        qsort(l + 1, ed, a, k);
    }
    
    private static void swap(int[] a, int x, int y) {
        int temp = a[x];
        a[x] = a[y];
        a[y] = temp;
    }
    
    public static void main(String[] args) {
    	System.out.println(GetLeastNumbers_Solution(new int[]{4,5,1,6,2,2,3,1}, 8));
    }
}