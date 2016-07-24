import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
    	Scanner cin = new Scanner(System.in);
    	String s = cin.next();
    	BigInteger a = new BigInteger(s);
    	BigInteger num[] = new BigInteger[8];
    	num[0] = new BigInteger("-128");
    	num[1] = new BigInteger("127");
    	num[2] = new BigInteger("-32768");
    	num[3] = new BigInteger("32767");
    	num[4] = new BigInteger("-2147483648");
    	num[5] = new BigInteger("2147483647");
    	num[6] = new BigInteger("-9223372036854775808");
    	num[7] = new BigInteger("9223372036854775807");
    	int i;
    	for (i = 0; i < 8; i += 2) {
    		if (a.compareTo(num[i]) != -1 && num[i + 1].compareTo(a) != -1) {
    			switch(i) {
    				case 0: System.out.println("byte"); break;
    				case 2: System.out.println("short"); break;
    				case 4: System.out.println("int"); break;
    				case 6: System.out.println("long"); break;
    			}
    			break;
    		}
    	}
    	if (i == 8) System.out.println("BigInteger");
    	cin.close();
    }
}
