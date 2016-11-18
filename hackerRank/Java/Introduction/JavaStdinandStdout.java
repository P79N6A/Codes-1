import java.util.*;

public class JavaStdinandStdout {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		while (scan.hasNext()) {
        	int a = scan.nextInt();
        	System.out.println(a);
        }
	}
}