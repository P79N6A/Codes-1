import java.util.Scanner;


public class Main {
	
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        int[] num = new int[n];
        for (int i = 0; i < n; ++i) {
        	num[i] = sc.nextInt();
        }
        for (int i = 0; i < k; ++i) {
        	int save = num[0];
        	for (int j = 0; j < n; ++j) {
        		if (j != n - 1) {
        			num[j] = (num[j] + num[j + 1]) % 100;
        		}
        		else num[j] = (num[j] + save) % 100;
        	}
        }
        for (int i1 = 0; i1 < n; ++i1) {
        	System.out.print(num[i1]);
        	if (i1 != n - 1) System.out.print(" ");
        }
        sc.close();
	}
}