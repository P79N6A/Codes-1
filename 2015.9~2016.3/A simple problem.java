import java.util.*;
import java.math.*;

public class Main 
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner ( System.in );
		BigInteger num[] = new BigInteger[100010];
		int op[] = new int[100010];
		int which[] = new int[100010];
		int t = cin.nextInt();
		int kase = 0;
		while (true)
		{
			t--;
			if (t < 0) break;
			// System.out.println(t);
			BigInteger ans1 = new BigInteger("1");
			BigInteger ans2 = new BigInteger("1");
			BigInteger temp;
			boolean flag[] = new boolean[100010];
			int n = cin.nextInt();
			BigInteger m = cin.nextBigInteger();
			System.out.printf("Case #%d:\n", ++kase);
			for (int i = 1; i <= n; ++i)
			{
				op[i] = cin.nextInt();
				if (op[i] == 1)
				{
					num[i] = cin.nextBigInteger();
				}
				else
				{
					which[i] = cin.nextInt();
					flag[which[i]] = true;
				}
			}
			
			for (int i = 1; i <= n; ++i)
			{
				if (op[i] == 1)
				{
					if (flag[i])
					{
						ans1 = ans1.multiply(num[i]);
					}
					else
					{
						ans2 = ans2.multiply(num[i]);
						ans2 = ans2.remainder(m);
					}
				}
				else
				{
					ans1 = ans1.divide(num[which[i]]);
				}
				temp = ans1.multiply(ans2);
				System.out.println(temp.remainder(m));
			}
		}
		cin.close();
	}
}