import static Print.Print.*;


public class Solution {
    
    private Object[] obj;
    private int next = 0;

    public Solution(int size) {
        obj = new Object[size];
    }
    
    public void add(Object x) {
        if (next < obj.length) {
            obj[next++] = x;
        }
    }
    
    
    
    private class GZY {
        String name = "GZY";
        @Override
        public String toString() {
            return name;
        }
  
    }
    
    private GZY gzy() {
        return new GZY();
    }
    
    public static void main(String[] args) {
        Solution cur = new Solution(3);
        for (int i = 0; i < 3; ++i) {
            cur.add(cur.gzy());
        }
        for (int i = 0; i < 3; ++i) {
            println(cur.obj[i]);
        }
    }
    
}