import java.util.*;

class FullStackException extends RuntimeException {}

class FixedSizeStack<T> {
	private int index;
	private final List<T> storage;
	private final int size;
	public FixedSizeStack(int size) {
		this.size = size;
		storage = new ArrayList<>(size);
	}
	public void push(T x) {
		if (index < size) {
			++index;
			storage.add(x);
		}
		else {
			throw new FullStackException();
		}
	}
	public T pop() {
		if (index > 0) {
			return storage.get(--index);
		}
		else {
			throw new EmptyStackException();
		}
	}
}

public class Solution {
	public static void main(String[] args) {
		FixedSizeStack<Integer> fss = new FixedSizeStack<>(10);
		for (int i = 0; i < 10; ++i) {
			fss.push(i);
		}
		for (int i = 0; i < 10; ++i) {
			System.out.println(fss.pop());
		}
	}
}