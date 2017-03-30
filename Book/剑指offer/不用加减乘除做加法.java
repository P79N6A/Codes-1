public class Solution {
    public int Add(int num1,int num2) {
        int shift = 1;
        int add = 0;
        int ret = 0;
        num1 ^= num2;
        while (true) {
            if ((num1 & shift) != 0) {
                if (add == 0)
                	ret |= shift;
                else add = 1;
            }
            else {
                if ((num2 & shift) == 0) {
                    if (add == 1) {
                        ret |= shift;
                        add = 0;
                    }
                }
                else {
                    if (add == 1) {
                        ret |= shift;
                    }
                    add = 1;
                }
            }
            if (shift == 1 << 31) break;
            shift <<= 1;
        }
        return ret;
    }
}
/*
 * while (num2 != 0) {
 *		int rawSum = num1 ^ num2; // 不计算进位的和
 *		num2 = (num1 & num2) << 1; // 计算了进位
 *		num1 = rawSum;
 * }
 * return num1;
 */