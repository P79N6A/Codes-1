import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int aa = in.nextInt(), bb = in.nextInt();
        int cc = in.nextInt(), dd = in.nextInt();
        boolean a = aa == 1 ? true : false;
        boolean b = bb == 1 ? true : false;
        boolean c = cc == 1 ? true : false;
        boolean d = dd == 1 ? true : false;
        boolean one = a ^ b;
        boolean two = c | d;
        boolean three = b & c;
        boolean four = a ^ d;
        boolean five = one & two;
        boolean six = three | four;
        System.out.println(five ^ six ? 1 : 0);
        
        in.close();
    }
}