public class Permutation {
    /**
     * 枚举全排列
     * @param s 需要排列的数组
     * @param pos 当前考虑的位置
     * 结束条件: 当排列长度达到rankString长度时,结束递归
     */
    public static void permutation(char[] s, int pos) {
        if (pos == s.length) {
            return;
        }
        // 考虑当前位置pos应该放入什么字符,放入的字符自动放到pos位置上,接着向pos+1递归
        for (int i = pos; i < s.length; ++i) {
            swap(s, pos, i);
            permutation(s, pos + 1);
            swap(s, pos, i);
        }
    }

    public static boolean nextPermutation(char[] s) {
        int n = s.length;
        int index = -1;
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] < s[i + 1]) {
                index = i;
                break;
            }
        }
        if (index == -1) return false;
        
        int nxtPos = n;
        while (--nxtPos > index) {
            if (s[nxtPos] > s[index]) break;
        }
        swap(s, index, nxtPos);
        int l = index, r = n;
        while (++l < --r) {
            swap(s, l, r);
        }
        
        return true;
    }
    
    public static boolean prePermutation(char[] s) {
        int n = s.length;
        int index = -1;
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] > s[i + 1]) {
                index = i;
                break;
            }
        }
        if (index == -1) return false;
        
        int nxtPos = n;
        while (--nxtPos > index) {
            if (s[nxtPos] < s[index]) break;
        }
        swap(s, index, nxtPos);
        int l = index, r = n;
        while (++l < --r) {
            swap(s, l, r);
        }
        
        return true;
    }
    
    /**
     * 交换char[]数组的两个元素
     * @param s 需要被交换的元素所在数组
     * @param x 第一个需要交换的位置
     * @param y 第二个需要交换的位置
     */
    private static void swap(char[] s, int x, int y) {
        char temp = s[x];
        s[x] = s[y];
        s[y] = temp;
    }
}