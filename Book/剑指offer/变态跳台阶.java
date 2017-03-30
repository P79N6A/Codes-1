import java.util.Scanner;

public class Main {
	
	public static int JumpFloorII(int target) {
        int[] ans = new int[target + 3];
        int[] sum = new int[target + 3];
        sum[1] = 1;
        ans[1] = 1;
        for (int i = 2; i <= target; ++i) {
        	ans[i] = sum[i - 1] + 1;
        	sum[i] = sum[i - 1] + ans[i];
        }
        return ans[target];
    }
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println(JumpFloorII(in.nextInt()));
		in.close();
	}
}