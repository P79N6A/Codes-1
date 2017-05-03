import java.util.*;
/**
 * 判断每一位是否相同即可
 */

public class Transform {
    public int calcCost(int A, int B) {
        int cnt = 0;
        for (int i = 0; i < 32; ++i) {
            if ((A & (1 << i)) != (B & (1 << i))) ++cnt;
        }
        return cnt;
    }
}