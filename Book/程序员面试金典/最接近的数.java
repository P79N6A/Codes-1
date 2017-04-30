import java.util.*;

public class CloseNumber {
    public int[] getCloseNumber(int x) {
        int[] ret = new int[2];
        ret[0] = x;
        int cnt = 0;
        for (int i = 0; i < 31; ++i) {
            if ((x & (1 << i)) == 0 && (x & (1 << (i + 1))) != 0) {
                ret[0] += (1 << i) - (1 << (i + 1));
                for (int j = 1; j <= cnt; ++j) {
                    ret[0] += (1 << (i - j));
                }
                break;
            }
            else if ((x & (1 << i)) != 0) {
                ret[0] -= (1 << i);
                ++cnt;
            }
        }
        ret[1] = x;
        cnt = 0;
        for (int i = 0; i < 31; ++i) {
            if ((x & (1 << i)) != 0 && (x & (1 << (i + 1))) == 0) {
                ret[1] += -(1 << i) + (1 << (i + 1));
                for (int j = 0; j < cnt; ++j) {
                    ret[1] += (1 << j);
                }
                break;
            }
            else if ((x & (1 << i)) != 0) {
                ret[1] -= (1 << i);
                ++cnt;
            }
        }
        return ret;
    }
}