import static Print.Print.*;

class Out {
    private int sum = 0;
    private void print() {
        println(sum);
    }
    
    public class In{
        void getprint() {
            print();
        }
        void getsum() {
            println(sum);
        }
    }
}


public class Solution {
    
    public static void main(String[] args) {
        Out test = new Out();
        (test.new In()).getprint();
    }
    
}