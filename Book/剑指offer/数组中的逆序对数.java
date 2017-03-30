public class Solution {
	final static int MOD = 1000000007;
	
    public static int InversePairs(int [] array) {
    	if (array == null) return 0;
        return mergeSort(array, 0, array.length - 1);
    }
    
    private static int mergeSort(int[] a, int bg, int ed) {
    	if (bg >= ed) return 0;
    	int mid = (ed - bg) / 2 + bg;
    	int left = mergeSort(a, bg, mid);
    	int right = mergeSort(a, mid + 1, ed);
    	
    	int[] temp = new int[ed - bg + 1];
    	int l = mid, r = ed, base = ed - bg;
    	int cnt = 0;
    	
    	while (l >= bg && r >= mid + 1) {
    		if (a[l] > a[r]) {
    			temp[base--] = a[l--];
    			cnt = (cnt + r - mid) % MOD;
    		}
    		else {
    			temp[base--] = a[r--];
    		}
    	}
    	
    	while (l >= bg) {
    		temp[base--] = a[l--];
    	}
    	
    	while (r >= mid + 1) {
    		temp[base--] = a[r--];
    	}
    	
    	for (int i : temp) {
    		a[bg++] = i;
    	}
    	return ((left + right) % MOD + cnt) % MOD;
    }
}