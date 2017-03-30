public class Solution {
    
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    
    public int integerReplacement(int n) {
        
        map.put(1, 0);
        map.put(2, 1);

        return dfs(n);
    }
    
    private int dfs(int n) {
        if (map.containsKey(n)) {
            return map.get(n);
        }
        
        int steps = -1;
        if (n % 2 == 0) {
            steps = dfs(n / 2) + 1;
        } else {
            steps = Math.min(dfs((n - 1)) + 1, dfs(1 + (n - 1) / 2) + 2);
        }
        
        map.put(n, steps);
        
        return steps;
    }
}