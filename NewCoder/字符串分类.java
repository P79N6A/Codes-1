import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        HashMap<String, Boolean> mp = new HashMap<>();
        for (int i = 0; i < n; ++i) {
        	char[] s = sc.next().toCharArray();
        	Arrays.sort(s);
        	mp.put(new String(s), true);
        }
        System.out.println(mp.size());
        sc.close();
	}
}