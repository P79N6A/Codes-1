import java.util.Scanner;

public class Input{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("�����ɶ��:");
		System.out.println("��������(����)��" + scanner.next()); // �հ׽���
		System.out.println("��������(��)��" + scanner.nextLine()); // �س�����
		scanner = new Scanner(System.in);
		System.out.println("�������ְɣ�");
		System.out.println("sqrt�ǣ�" + two(scanner.nextInt()));
	}
	
	public static double two(int x) {
		return Math.sqrt(x);
	}
}