import java.util.Scanner;
/*
 * 题目需要找出一段长度大于等于L的连续非负整数，使得其和等于N。L要尽可能小。
 * 考虑是连续非负整数，所以其和我们能用中位数来表示，分两种情况：
 * 情况一，长度为奇数的情况：
 *   此时中位数一定是整数，N = 中位数 x L
 * 情况二，长度为偶数的情况：
 *   此时中位数肯定是xx.5的形式，N = xx.5 * L
 * 所以我们从长度L开始枚举，至100为止，分奇偶讨论。
 */
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), l = in.nextInt();
		in.close();
		int bg = -1, ed = -1;
		for (int i = l; i <= 100; ++i) {
			// 奇数，中位数一定是整数
			if (i % 2 == 1 && n % i == 0) {
				int mid = n / i;
				bg = mid - (i - 1) / 2;
				ed = mid + (i - 1) / 2;
				if (bg >= 0) // 答案要合法，即需要是非负整数
					break;
			}
			// 偶数，中位数一定是0.5形式
			if (i % 2 == 0 && (double)n / i - n / i == 0.5f) {
				int mid = n / i;
				bg = mid - i / 2 + 1;
				ed = mid + i / 2;
				if (bg >= 0)
					break;
			}
		}
		if (bg >= 0) {
			for (int i = bg; i < ed; ++i) {
				System.out.print(i + " ");
			}
			System.out.println(ed);
		}
		else {
			System.out.println("No");
		}
	}
}