import static Print.Print.*;

interface ShortLife {
    void say();
}

public class Solution {
    static ShortLife Acc() {
        return new ShortLife() {
            @Override
            public void say() {
                throw new UnsupportedOperationException("Not supported yet.");
            }

            @Override
            public String toString() {
                return "what?";
            }
        };
    } 
    
    public static void main(String[] args) {
        println(Acc());
    }
}