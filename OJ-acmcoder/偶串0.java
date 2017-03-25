import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s = in.next();
		int[] num = new int[s.length()];
		int[] sum = new int[s.length()];
		for (int i = 0; i < s.length(); ++i) {
			num[i] = 1 << (s.charAt(i) - 'a');
		}
		sum[0] = num[0];
		long cnt = 0;
		for (int i = 1; i < num.length; ++i) {
			sum[i] ^= sum[i - 1] ^ num[i];
			if (sum[i] == 0) ++cnt;
		}
		
		long last = cnt;
		int del = 0;
		for (int i = 1; i < num.length; ++i) {
			del ^= num[i - 1];
			if (sum[i - 1] == 0) --last;
			if (del == 0) {
				cnt += last;
			}
			else {
				for (int j = i; j < num.length; ++j) {
					if ((sum[j] ^ del) == 0) ++cnt;
				}
			}
		}
		
		System.out.println(cnt);
		in.close();
	}
}