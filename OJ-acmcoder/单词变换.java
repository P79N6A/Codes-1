import java.util.*;

public class Main {
    
    private static final int INF = 100000000;
    private static ArrayList<String> word = new ArrayList<>();
    private static int n;
    private static int[][] mp;
    private static int[] dis;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String bg = in.next();
        String ed = in.next();
        in.skip("\n");
        String[] words = in.nextLine().split(" ");
        int bid = 0, eid = 0;
        word.add(bg);
        for (int i = 0; i < words.length; ++i) {
            word.add(words[i]);
            if (words[i].equals(ed)) {
                eid = i + 1;
            }
        }
        n = words.length + 1;
        mp = new int[n][n];
        dis = new int[n];
        for (int i = 0; i < n; ++i) {
            dis[i] = INF;
            mp[i][i] = 0;
            for (int j = i + 1; j < n; ++j) {
                String u = word.get(i), v = word.get(j);
                int cnt = 0;
                for (int k = 0; k < u.length(); ++k) {
                    if (u.charAt(k) != v.charAt(k) && ++cnt > 1) {
                        break;
                    }
                }
                //System.out.println(u + " " + v + " " + cnt);
                if (cnt == 1) mp[i][j] = mp[j][i] = 1;
                else mp[i][j] = mp[j][i] = INF;
            }
        }
        
        dis[0] = 0;
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        while (q.size() != 0) {
            int cur = q.poll();
            for (int i = 0; i < n; ++i) {
                if (mp[cur][i] != INF && dis[i] > dis[cur] + mp[cur][i]) {
                    dis[i] = dis[cur] + mp[cur][i];
                    q.add(i);
                }
            }
        }
        System.out.println(dis[eid] + 1);
        in.close();
    }
}