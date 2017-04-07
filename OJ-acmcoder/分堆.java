import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), k = in.nextInt();
        int split = k + (k + 1);
        int ans = n / split * 2;
        if (n % split >= k) ++ans;
        System.out.println(ans);
        in.close();
    }
}