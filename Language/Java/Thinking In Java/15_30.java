class Holder<T> {
	private T value;
	public void set(T x) {
		value = x;
	}
	public T get() {
		return value;
	}
}

public class Solution {
	public static void main(String[] args) {
		Holder<Byte> bt = new Holder<>();
		bt.set((byte) 1);
		System.out.println(bt.get() == (byte)1);
		Holder<Integer> it = new Holder<>();
		it.set(1);
		System.out.println(it.get() == 1);
	}
}