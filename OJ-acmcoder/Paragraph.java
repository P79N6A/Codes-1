import java.util.*;

public class Main {
    
    static Map<String, Integer> mp = new HashMap<>();
    static int id = 0;
    
    static int get(String name) {
        if (mp.containsKey(name)) {
            return mp.get(name);
        }
        mp.put(name, ++id);
        return id;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String[] tt = in.nextLine().split(" ");
        int n = Integer.parseInt(tt[0]), m = Integer.parseInt(tt[1]);
        Set[] st = new HashSet[n];
        String[] sss = new String[n];
        for (int i = 0; i < n; ++i) {
            char[] s = in.nextLine().toCharArray();
            sss[i] = new String(s);
            //System.err.println(sss[i]);
            for (int j = 0; j < s.length; ++j) {
                if (Character.isUpperCase(s[j])) {
                    s[j] = (char)(s[j] - 'A' + 'a');
                }
            }
            String[] str = new String(s).split(" ");
            st[i] = new HashSet<Integer>();
            for (String ss : str) {
                st[i].add(get(ss));
            }
        }
        for (int i = 0; i < m; ++i) {
            char[] s = in.nextLine().toCharArray();
            for (int j = 0; j < s.length; ++j) {
                if (Character.isUpperCase(s[j])) {
                    s[j] = (char)(s[j] - 'A' + 'a');
                }
            }
            String[] str = new String(s).split(" ");
            Set<Integer> temp = new HashSet<>();
            for (String ss : str) {
                temp.add(get(ss));
            }
            int ans = 0, mx = 0;
            for (int j = 0; j < n; ++j) {
                int sum = 0;
                for (Object k : st[j]) {
                    if (temp.contains(k)) ++sum;
                }
                if (sum > mx) {
                    mx = sum;
                    ans = j;
                }
            }
            System.out.println(sss[ans]);
        }
        in.close();
    }
}
