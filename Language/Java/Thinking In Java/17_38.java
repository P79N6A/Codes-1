package src;

import java.util.*;

public class Solution {
	private static void fill(Map<Integer, Integer> mp) {
		for (int i = 1; i < 6; i++) {
			mp.put(i, i + 1);
		}
	}
	
	private static void test(Map<Integer, Integer> mp) {
		for (int i = 0; i < 1000000; i++) {
			for (int j = 0; j < 10; ++j) {
				mp.get(j);
			}
		}
	}
	
	public static void main(String[] args) {
		Map<Integer, Integer> mp1 = new HashMap<>(10);
		fill(mp1);
		long t;
		t = System.currentTimeMillis();
		test(mp1);
		System.out.println(System.currentTimeMillis() - t);
		
		Map<Integer, Integer> mp2 = new HashMap<>(20);
		fill(mp2);
		t = System.currentTimeMillis();
		test(mp2);
		System.out.println(System.currentTimeMillis() - t);
	}
}
