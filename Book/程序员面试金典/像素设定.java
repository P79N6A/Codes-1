import java.util.*;
// 虽然时间复杂度比起直接for循环赋值要优
// 然而要考虑各种边界，sad
public class Render {
    public int[] renderPixel(int[] screen, int x, int y) {
        int xs = x / 8, xe = x % 8;
        int ys = y / 8, ye = y % 8;
        for (int i = xs + 1; i < ys; ++i) {
            screen[i] = 255;
        }
        for (int i = xe; i < 8; ++i) {
            screen[xs] |= 1 << i;
        }
        for (int i = (xs == ys ? xe : 0); i <= ye; ++i) {
            screen[ys] |= 1 << i;
        }
        return screen;
    }
}