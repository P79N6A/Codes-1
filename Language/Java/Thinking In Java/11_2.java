import java.util.Collection;
import java.util.HashSet;

public class Solution {
    public static void main(String[] args) {
        Collection<Integer> c = new HashSet<>();
        for (int i = 0; i < 5; ++i) {
            c.add(i);
        }
        for (int i = 0; i < 5; ++i) {
            c.add(i);
        }
        for (Integer i : c) {
            System.out.println(i);
        }
    }
}