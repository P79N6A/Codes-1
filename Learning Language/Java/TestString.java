public class TestString {
	public static void main(String[] args) {
		char charArr[] = {'H', 'e', 'l', 'l', 'o'};
		String s = new String(charArr);
		System.out.println(s.indexOf("llo"));
		System.out.println(s.charAt(1));
		
		// equalsIgnoreCase()
		// compareTo()
		// regionMatches 比较某一部分是否相等
		// startsWith(prefix) Is it starting with this prefix?
		// endsWith(suffix)
		// concat()
		// substring(a, b) return string[a, b]
		// replace(a, b)
	}
}