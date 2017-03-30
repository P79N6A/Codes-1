// Solution: strictly increasing
public class Solution {
    public int minNumberInRotateArray(int [] array) {
    	if (array.length == 0) return 0;
    	int l = 0, r = array.length - 1;
    	int ret = 0;
    	while (l <= r) {
    		int mid = ((r - l) >> 1) + l;
    		if (array[mid] >= array[ret]) {
    			ret = mid;
    			l = mid + 1;
    		}
    		else {
    			r = mid - 1;
    		}
    	}
    	return ret == array.length - 1 ? array[0] : array[ret + 1];
    }
}

// Solution: none decreasing
public class Solution {
    public int minNumberInRotateArray(int [] array) {
    	if (array.length == 0) return 0;
    	for (int i = 1; i < array.length; ++i) {
    		if (array[i] < array[i - 1])
    			return array[i];
    	}
    	return array[0];
    }
}