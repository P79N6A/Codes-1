class BerylliumSphere {}

public class Main {
	static void f(BerylliumSphere[] b) {
		System.out.println(b.length);
	}
	public static void main(String[] args) {
		//f({new BerylliumSphere(), new BerylliumSphere[]});
		f(new BerylliumSphere[]{new BerylliumSphere(), new BerylliumSphere()});
	}
}