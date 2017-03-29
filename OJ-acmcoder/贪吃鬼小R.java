import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        int n;
        Scanner in = new Scanner(System.in);
        final BigInteger two = BigInteger.valueOf(2), three = BigInteger.valueOf(3);
        while (in.hasNext()) {
            n = in.nextInt();
            BigInteger ans = BigInteger.ONE;
            for (int i = 1; i < n; ++i) {
                ans = ans.add(three);
                ans = ans.multiply(two);
            }
            System.out.println(ans);
        }
    }
}
