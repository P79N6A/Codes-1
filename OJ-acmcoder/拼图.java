import java.util.*;

public class Main {
    
    private static final long INF = (long)1e16;
    private static int[] dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Map bg = new Map();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                bg.set(i, j, in.nextInt());
            }
        }
        bg.dis = 0;
        int ans = -1;
        Queue<Map> queue = new LinkedList<>();
        HashMap<Long, Boolean> vis = new HashMap<>();
        vis.put(bg.hash(), true);
        queue.add(bg);
        while (!queue.isEmpty()) {
            Map cur = queue.poll();
            //System.out.println(cur.hash());
            if (cur.hash() == 123456780L) {
                ans = cur.dis;
                break;
            }
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (cur.get(i, j) == 0) {
                        for (int k = 0; k < 4; ++k) {
                            int nx = i + dx[k], ny = j + dy[k];
                            if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
                                cur.set(i, j, cur.get(nx, ny));
                                cur.set(nx, ny, 0);
                                if (!vis.containsKey(cur.hash())) {
                                    vis.put(cur.hash(), true);
                                    queue.add(new Map(cur));
                                }
                                cur.set(nx, ny, cur.get(i, j));
                                cur.set(i, j, 0);
                            }
                        }
                        break;
                    }
                }
            }
        }
        System.out.println(ans);
        in.close();
    }
}

class Map {
    private int[][] mp = new int[3][3];
    public int dis = 0;
    private long hashVal = 0;
    
    public Map(){}
    public Map(Map save) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                mp[i][j] = save.get(i, j);
            }
        }
        dis = save.dis + 1;
    }
    
    public void set(int x, int y, int val) {
        mp[x][y] = val;
    }
    
    public int get(int x, int y) {
        return mp[x][y];
    }
    
    public long hash() {
        hashVal = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                hashVal *= 10;
                hashVal += mp[i][j];
            }
        }
        return hashVal;
    }
}