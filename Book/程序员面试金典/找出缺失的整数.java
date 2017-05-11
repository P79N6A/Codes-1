import java.util.*;
// 非最优
// 最优应该是利用已经排好序这个特点，那么当i % 2 != numbers[i][0] 时
// 这个数即为所求缺失数i
public class Finder {
    public int findMissing(int[][] numbers, int n) {
        int cmp = 0;
        for (int i = 0; i < numbers.length; ++i) {
            for (int j = 0; j < numbers[i].length; ++j) {
                if (numbers[i][j] == 1) {
                    cmp ^= 1 << j;
                }
            }
        }
        int cmp2 = 0;
        for (int i = 1; i <= n; ++i) {
            cmp2 ^= i;
        }
        return cmp ^ cmp2;
    }
}