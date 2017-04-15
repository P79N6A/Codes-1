import java.util.*;

public class Same {
    public boolean checkSam(String stringA, String stringB) {
        int[] sum = new int[256];
        for (char c : stringA.toCharArray()) {
            ++sum[c];
        }
        for (char c : stringB.toCharArray()) {
            if (--sum[c] < 0) return false;
        }
        return true;
    }
}