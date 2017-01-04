import static Print.Print.*;
import java.util.*;


public class Solution {
    public static void main(String[] args) {
        Map<Integer, String> a = new HashMap<>();
        for (int i = 0; i < 10; ++i) {
            a.put(i * 245, String.valueOf(i));
        }
        Map<Integer, String> b = new LinkedHashMap<>();
        for (int i : a.keySet()) {
            println(Integer.hashCode(i));
            b.put(i, String.valueOf(i));
        }
        println(a.keySet());
        println(b.keySet());
    }
}