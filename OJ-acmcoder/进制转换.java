import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            char[] org = in.next().toCharArray();
            long ans = 0;
            for (int i = 0; i < org.length; ++i) {
                ans *= 26;
                ans += org[i] - 'a';
            }
            System.out.println(ans);
        }
        in.close();
    }
}