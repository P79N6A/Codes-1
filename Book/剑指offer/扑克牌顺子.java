import java.util.Arrays;
public class Solution {
    public boolean isContinuous(int [] numbers) {
        if (numbers.length == 0) return false;
        Arrays.sort(numbers);
        int p = 0;
        while (numbers[p] == 0) ++p;
        for (int i = p; i < 5; ++i) {
            for (int j = i + 1; j < 5; ++j) {
                if (numbers[i] > 13 || numbers[i] == numbers[j])
                    return false;
            }
        }
        if (numbers[0] >= 0 && p != 5 && numbers[numbers.length - 1] - numbers[p] <= 4 && numbers.length == 5) {
            return true;
        }
        return false;
    }
}