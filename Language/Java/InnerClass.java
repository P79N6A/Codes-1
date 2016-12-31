class Outer {
	public void test() {
		Inner t = new Inner();
		t.ok();
		System.out.println("I'm fine.");
	}
	
	class Inner {
		void ok() {
			System.out.println("Are you ok?");
		}
	}
}


public class InnerClass {
	public static void main(String args[]) {
		Outer a = new Outer();
		a.test();
	}
}