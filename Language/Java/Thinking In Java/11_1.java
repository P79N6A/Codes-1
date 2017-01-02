import java.util.ArrayList;

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
        ArrayList<Gerbil> a = new ArrayList<>();
        for (int i = 0; i < 5; ++i) {
            a.add(new Gerbil());
        }
        for (Gerbil g : a) {
            g.hop();
        }
    }
}