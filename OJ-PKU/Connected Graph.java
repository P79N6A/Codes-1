import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
    	Scanner cin = new Scanner(System.in);
    	BigInteger p[] = new BigInteger[60];
    	BigInteger ok[] = new BigInteger[60];
    	BigInteger nok[] = new BigInteger[60];
    	BigInteger tol[] = new BigInteger[60];
    	BigInteger C[][] = new BigInteger[60][60];
    	p[0] = BigInteger.ONE;
    	BigInteger two = new BigInteger("2");
    	for (int i = 1; i <= 50; ++i) p[i] = p[i - 1].multiply(two);
    	for (int i = 0; i <= 50; ++i) {
    		nok[i] = BigInteger.ZERO;
    		C[i][0] = C[i][i] = BigInteger.ONE;
    		for (int j = 1; j < i; ++j) {
    			C[i][j] = C[i - 1][j - 1].add(C[i - 1][j]);
    		}
    	}
    	
    	tol[1] = BigInteger.ONE;
    	ok[1] = BigInteger.ONE;
    	for (int i = 2; i <= 50; ++i) {
    		for (int j = 1; j < i; ++j) {
    			nok[i] = nok[i].add((C[i - 1][j - 1].multiply(ok[j])).multiply(tol[i - j]));
    			//System.out.println((C[i - 1][j - 1].multiply(ok[j])).multiply(tol[i - j]));
    			//System.out.println(nok[i]);
    		}
    		tol[i] = tol[i - 1].multiply(p[i - 1]);
    		ok[i] = tol[i].subtract(nok[i]);
    	}
    	while (cin.hasNext()) {
    		int n = cin.nextInt();
    		if (n == 0) break;
    		System.out.println(ok[n]);
    	}
    	cin.close();
    }
}