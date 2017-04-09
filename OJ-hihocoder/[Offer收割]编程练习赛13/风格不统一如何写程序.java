import java.util.*;

public class Main {
    
    private static final long INF = (long)1e16;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 0; i < n; ++i) {
            String s = in.next();
            int flag = 0;
            for (int j = 0; j < s.length(); ++j) {
                char cur = s.charAt(j);
                if (cur == '_') {
                    flag = 1;
                    break;
                }
                if (Character.isUpperCase(cur)) {
                    flag = 2;
                    break;
                }
            }
            switch (flag) {
                case 1:
                    String[] str = s.split("_");
                    System.out.print(str[0]);
                    for (int j = 1; j < str.length; ++j) {
                        char[] cur = str[j].toCharArray();
                        cur[0] = Character.toUpperCase(cur[0]);
                        System.out.print(cur);
                    }
                    break;
                case 2:
                    for (int j = 0; j < s.length(); ++j) {
                        char cur = s.charAt(j);
                        if (Character.isUpperCase(cur)) {
                            System.out.print("_" + Character.toLowerCase(cur));
                        }
                        else System.out.print(cur);
                    }
                    break;
                default:
                    System.out.print(s);
                    break;
            }
            System.out.println();
        }
        in.close();
    }
}