import java.util.Stack;

public class Solution {
    public static boolean IsPopOrder(int [] a,int [] b) {
        Stack<Integer> sta = new Stack<>();
        int posa = 0, posb = 0, up = a.length;
        while (posa < up) {
            if (sta.size() != 0 && sta.peek() == b[posb]) {
                sta.pop();
                ++posb;
            }
            else if (a[posa] == b[posb]) {
                ++posb;
            }
            else {
                sta.push(a[posa]);
            }
            ++posa;
        }
        while (sta.size() != 0) {
            if (sta.peek() != b[posb]) return false;
            ++posb;
            sta.pop();
        }
        return true;
    }
	public static void main(String[] args) {
		int[] a = {1, 2, 3, 4, 5};
		int[] b = {4, 3, 5, 1, 2};
		System.out.println(IsPopOrder(a, b));
	}
}