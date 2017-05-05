import java.util.*;

// 还能这样：return ((x & 0xaaaaaaaa) >>> 1) | ((x & 0x555555555) << 1)

public class Exchange {
    public int exchangeOddEven(int x) {
        for (int i = 0; i < 32; i += 2) {
            int a = x & (1 << i);
            int b = x & (1 << (i + 1));
            x += a - (b >> 1);
        }
        return x;
    }
}