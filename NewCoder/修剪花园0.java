import java.util.Scanner;

public class Main {
	
	static int n;
	static int[] num;
	
	static void add(int index, int val) {
		for (int i = index; i <= n; i += (i & -i)) {
			num[i] += val;
		}
	}
	
	static int sum(int index) {
		int ret = 0;
		for (int i = index; i > 0; i -= (i & -i)) {
			ret += num[i];
		}
		return ret;
	}
	
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
        	n = in.nextInt();
        	int m = in.nextInt();
        	num = new int[n + 2];
        	for (int i = 1; i <= n; ++i) {
        		add(i, in.nextInt());
        	}
        	String s;
        	int x, y;
        	while (m-- != 0) {
        		s = in.next();
        		x = in.nextInt();
        		y = in.nextInt();
        		if (s.charAt(0) == 'Q') {
        			System.out.println(sum(Math.min(x + y, n)) - sum(Math.max(x - y - 1, 0)));
        		}
        		else if (s.charAt(0) == 'C') {
        			int numx = sum(x) - sum(x - 1);
        			int numy = sum(y) - sum(y - 1);
        			int diff = Math.abs(numx - numy);
        			if (numx > numy) {
        				add(x, -diff);
        				add(y, diff);
        			}
        			else {
        				add(x, diff);
        				add(y, -diff);
        			}
        		}
        		else if (s.charAt(0) == 'D') {
        			add(x, -y);
        		}
        		else {
        			add(x, y);
        		}
        	}
        }
        in.close();
    }
}