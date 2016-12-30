import static Print.Print.*;


public class Solution {
    
    private String x;

    public Solution(String x) {
        this.x = x;
    }
    
    class Inner {
        @Override
        public String toString() {
            return x;
        }
    }
    
    private Inner getInner() {
        return new Inner();
    }
    
    public static void main(String[] args) {
        Solution cur = new Solution("hahahah");
        println(cur.getInner());
    }
    
}