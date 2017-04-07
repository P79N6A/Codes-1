import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a = Integer.parseInt(in.next(), 2);
        int b = Integer.parseInt(in.next(), 2);
        System.out.println(a ^ b);
    }
}