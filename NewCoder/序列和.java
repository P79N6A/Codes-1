import java.util.Scanner;
/*
 * ��Ŀ��Ҫ�ҳ�һ�γ��ȴ��ڵ���L�������Ǹ�������ʹ����͵���N��LҪ������С��
 * �����������Ǹ������������������������λ������ʾ�������������
 * ���һ������Ϊ�����������
 *   ��ʱ��λ��һ����������N = ��λ�� x L
 * �����������Ϊż���������
 *   ��ʱ��λ���϶���xx.5����ʽ��N = xx.5 * L
 * �������Ǵӳ���L��ʼö�٣���100Ϊֹ������ż���ۡ�
 */
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), l = in.nextInt();
		in.close();
		int bg = -1, ed = -1;
		for (int i = l; i <= 100; ++i) {
			// ��������λ��һ��������
			if (i % 2 == 1 && n % i == 0) {
				int mid = n / i;
				bg = mid - (i - 1) / 2;
				ed = mid + (i - 1) / 2;
				if (bg >= 0) // ��Ҫ�Ϸ�������Ҫ�ǷǸ�����
					break;
			}
			// ż������λ��һ����0.5��ʽ
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