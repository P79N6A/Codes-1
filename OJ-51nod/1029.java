import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigInteger a = in.nextBigInteger(), b = in.nextBigInteger();
		BigInteger []ans = a.divideAndRemainder(b);
		System.out.println(ans[0]);
		System.out.println(ans[1]);
	}
}