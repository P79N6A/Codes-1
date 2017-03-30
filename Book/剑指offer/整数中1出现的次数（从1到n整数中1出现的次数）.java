// 考虑每一个位置对1的贡献 = 该位置往前 + 该位置往后
public class Solution {
    public int NumberOf1Between1AndN_Solution(int n) {
        int ret = 0, base = 1;
        while (n / base != 0) {
        	// n / (base * 10) <-- 大于当前位的部分
        	// 该位置往前 ，base为该位置能提供的1数量
        	ret += n / (base * 10) * base;
        	// 高位往后的部分贡献
        	int high = n % (base * 10) / base;
        	if (high > 1) ret += base;
        	else if (high == 1) ret += n % base + 1;
        	base *= 10;
        }
        return ret;
    }
}