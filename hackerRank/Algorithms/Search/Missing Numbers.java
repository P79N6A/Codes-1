import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
    	Scanner in = new Scanner(System.in);
    	int[] a = new int[10005];
    	int[] b = new int[10005];
    	int n = in.nextInt();
    	for (int i = 0; i < n; ++i) {
    		int x = in.nextInt();
    		++a[x];
    	}
    	n = in.nextInt();
    	for (int i = 0; i < n; ++i) {
    		int x = in.nextInt();
    		++b[x];
    	}
    	for (int i = 0; i < 10001; ++i) {
    		if (a[i] != b[i]) System.out.print(i + " ");
    	}
    }
}