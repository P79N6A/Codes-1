public class Search {
    /**
     * 
     * @param a the array to be searched
     * @param l the index of the first element (inclusive) to be
     *          searched
     * @param r the index of the last element (inclusive) to be searched
     * @param key the value to be searched for
     * @return the index of the value who is the first one equals or upper 
     * to the key. If not find returns (r + 1)
     */
    public static int lowerBound(Comparable[] a, int l, int r, Comparable key) {
        int ret = r + 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            int cmp = a[mid].compareTo(key);
            if (cmp >= 0) {
                ret = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ret;
    }
    
    /**
     * 
     * @param a the array to be searched
     * @param l the index of the first element (inclusive) to be
     *          searched
     * @param r the index of the last element (inclusive) to be searched
     * @param key the value to be searched for
     * @return the index of the value who is the first one upper to
     * he key. If not find returns (r + 1)
     */
    public static int upperBound(Comparable[] a, int l, int r, Comparable key) {
        int ret = r + 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            int cmp = a[mid].compareTo(key);
            if (cmp > 0) {
                ret = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ret;
    }
}