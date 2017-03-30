public class Solution {
    public double Power(double base, int exponent) {
        double ret = 1.0;
        if (exponent < 0) {
            exponent = -exponent;
            base = 1 / base;
        }
        while (exponent != 0) {
        	if ((exponent & 1) == 1)
        		ret *= base;
        	base = base * base;
        	exponent >>= 1;
        }
        return ret;
    }
}