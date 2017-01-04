import java.util.*;

class Gerbil {
    static int count = 0;
    int gerbilNumber;
    public Gerbil() {
        gerbilNumber = ++count;
    }
    void hop() {
        System.out.println(gerbilNumber + " is hopping.");
    }
}

public class Solution {
    public static void main(String[] args) {
        Map<Gerbil, Integer> a = new HashMap<>();
        for (int i = 0; i < 5; ++i) {
            Gerbil temp = new Gerbil();
            a.put(temp, temp.gerbilNumber);
        }
        Iterator<Gerbil> it = a.keySet().iterator();
        while (it.hasNext()) {
            Gerbil cur = it.next();
            System.out.println(cur);
            cur.hop();
        }
    }
}