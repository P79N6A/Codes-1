import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int offset = in.nextInt();
            int n = in.nextInt();
            int l1 = in.nextInt();
            int l2 = in.nextInt();
            
            int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
            if (offset <= l1 + l2) {
            	if (offset >= l1) {
            		ans1 = l1;
            		ans2 = l1;
            		ans3 = offset - l1;
            		ans4 = Math.min(l2, ans3 + n);
            	}
            	else {
            		ans1 = offset;
            		if (offset + n > l1) {
            			ans2 = l1;
            			ans4 = Math.min(l2, n - (l1 - offset));
            		}
            		else {
            			ans2 = offset + n;
            		}
            	}
            }
            else {
            	ans1 = ans2 = l1;
            	ans3 = ans4 = l2;
            }
            
            System.out.printf("%d %d %d %d\n", ans1, ans2, ans3, ans4);
        }
    }
}