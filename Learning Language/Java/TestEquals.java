public class TestEquals {
	public static void main(String[] args) {
		String s1 = new String("Java");
		String s2 = new String("Java");
		//String s1 = "Java";
		//String s2 = "Java";
		if (s1 == s2) System.out.println("s1 == s2\n");
		if (s1.equals(s2)) System.out.println("s1 equals to s2\n");
		int a = 10, b = 10;
		if (a == b) System.out.println(a);
	}
}