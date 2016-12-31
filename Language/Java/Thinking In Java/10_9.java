import static Print.Print.*;

interface ShortLife {
    void say();
}


public class Solution {
    
    static ShortLife Acc() {
        class SaveYourLife implements ShortLife {

            @Override
            public void say() {
                print("Oh~ Life is too short!");
            }

            @Override
            public String toString() {
                return "adfsadf";
            }
            
            
          
        }
        return new SaveYourLife();
    } 
    
    public static void main(String[] args) {
        println(Acc());
    }
    
}