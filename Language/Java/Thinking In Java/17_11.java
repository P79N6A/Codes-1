package src;

import java.util.*;

class Int implements Comparable<Int> {
	private static Random rnd = new Random();
	public Integer i;
	
	public Int() {
		i = rnd.nextInt(100);
	}
	
	@Override
	public int compareTo(Int o) {
		if (i < o.i) return 1;
		return -1;
	}
	
	@Override
	public String toString() {
		return i.toString();
	}
	
}

public class Solution {
	public static void main(String[] args) {
		PriorityQueue<Int> pq = new PriorityQueue<>();
		for (int i = 0; i < 10; ++i) {
			pq.add(new Int());
		}
		while (pq.size() != 0) {
			System.out.print(pq.poll() + " ");
		}
	}
}
