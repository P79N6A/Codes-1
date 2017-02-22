import java.util.*;

public class Solution {
	static void test(String s, List<String> list) {
		System.out.println("------- " + s + " -------");
		// List<String> subList = list.subList(0, 3);
		List<String> subList = new ArrayList<>(list.subList(0, 3));
		try {
			list.add(0, "hello");
		} catch (Exception e) {
			System.out.println("add(): " + e);
		}
		try {
			list.addAll(0, subList);
		} catch (Exception e) {
			System.out.println("list.addAll(): " + e);
		}
		try {
			list.remove(0);
		} catch (Exception e) {
			System.out.println("list.remove(): " + e);
		}
	}
	public static void main(String[] args) {
		List<String> list = Arrays.asList("A B C D E F G".split(" "));
		test("Modifiable Copy", new ArrayList<>(list));
		test("Arrays.asList()", list);
		test("unmodifiableList()", Collections.unmodifiableList(
				new ArrayList<String>(list)));
	}
}