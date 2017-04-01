import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        char[] s = in.next().toCharArray();
        boolean neg = true;
        for (int i = 0; i < s.length; ++i) {
            if (s[i] == '+') {
                neg = false;
                s[i] = ' ';
            }
            if (s[i] == '-') {
                s[i] = ' ';
            }
        }
        String ss = new String(s);
        String[] num = ss.split(" ");
        int a = Integer.parseInt(num[0]);
        int b = Integer.parseInt(num[1]);
        
        for (int i = 0; i < a; ++i) System.out.print("+");
        System.out.println(">");
        for (int i = 0; i < b; ++i) System.out.print("+");
        System.out.println(">");
        if (neg) System.out.println("<[<->-]<");
        else System.out.println("<[<+>-]<");
        System.out.println("++++++++++++++++++++++++++++++++++++++++++++++++.");
        in.close();
    }
}