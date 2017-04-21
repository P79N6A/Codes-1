import java.util.*;

public class TwoStacks {
    public static ArrayList<Integer> twoStacksSort(int[] numbers) {
        Stack<Integer> org = new Stack<>();
        Stack<Integer> res = new Stack<>();
        for (int i = numbers.length - 1; i >= 0; --i) {
            org.push(numbers[i]);
        }
        while (!org.empty()) {
            if (res.empty()) {
                res.push(org.pop());
            }
            else {
                int i = org.pop();
                if (i >= res.peek()) {
                    res.push(i);
                }
                else {
                    while (!res.empty() && res.peek() > i) {
                        org.push(res.pop());
                    }
                    res.push(i);
                }
            }
        }
        ArrayList<Integer> ret = new ArrayList<>();
        while (!res.empty()) {
            ret.add(res.pop());
        }
        return ret;
    }
}