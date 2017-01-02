import java.util.*;

class Gen {
    String[] item;
    int pos = 0;
    public Gen(String[] list) {
        item = list;
    }
    public void add(Collection x) {
        for (int i = 0; i < 3; ++i) {
            x.add(next());
        }
        System.out.println(x);
    }
    private String next() {
        if (pos == item.length) pos = 0;
        return item[pos++];
    }
}

public class Solution {
    public static void main(String[] args) {
        Gen myGen = new Gen(new String[]{"hello", "world"});
        myGen.add(new ArrayList<String>());
        myGen.add(new LinkedList<String>());
        myGen.add(new HashSet<String>());
        myGen.add(new LinkedHashSet<String>());
        myGen.add(new TreeSet<String>());
    }
}