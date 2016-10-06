import java.util.Scanner;

public class Input{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("输入点啥吧:");
		System.out.println("你输入了(单个)：" + scanner.next()); // 空白结束
		System.out.println("你输入了(行)：" + scanner.nextLine()); // 回车结束
		scanner = new Scanner(System.in);
		System.out.println("输入数字吧：");
		System.out.println("sqrt是：" + two(scanner.nextInt()));
	}
	
	public static double two(int x) {
		return Math.sqrt(x);
	}
}