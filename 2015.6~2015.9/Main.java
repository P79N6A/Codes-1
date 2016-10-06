import java.util.Scanner;
import java.math.*;
import java.text.*;
public class Main
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner ( System.in );
		BigInteger dp[] = new BigInteger[10001];
		BigInteger two = new BigInteger("2");
		dp[0] = BigInteger.ZERO;
		dp[1] = BigInteger.ONE;
		int k = 1;
		for (int i = 2; i <= 10000; ++i)
		{
			BigInteger add = BigInteger.ONE.shiftLeft(k);
			for (int j = 0; j < k + 1 && i + j <= 10000; ++j)
			{
				dp[i + j] = dp[i + j - 1].add(add);
			}
			i += k;
			++k;
		}
		while (cin.hasNextBigInteger())
		{
			int n = cin.nextInt();
			System.out.println(dp[n]);
		}
        cin.close();
	}
}
