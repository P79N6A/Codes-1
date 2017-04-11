import java.util.*;

public class Main {
    
    private static final long INF = (long)1e16;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        ArrayList<Integer> al = new ArrayList<>();
        int j = 2;
        while (n >= j) {
            al.add(j);
            n -= j;
            ++j;
        }
        j = al.size() - 1;
        for (int i = 0; i < n; ++i) {
            al.set(j, al.get(j) + 1);
            if (--j < 0) j = al.size() - 1;
        }
        long ans = 1;
        for (int i : al) {
            //System.err.println(n);
            ans *= i;
        }
        System.out.println(ans);
        in.close();
    }
}