import java.util.*;

class Pair {
    int x, y;
    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Solution {
    
    int[] dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};
    
    int decompose(int x) {
        int ret = 0;
        while (x != 0) {
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
    
    public int movingCount(int threshold, int rows, int cols) {
        if (rows < 0 || cols < 0) return 0;
        boolean[][] vis = new boolean[rows][cols];
        int ans = 0;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0, 0));
        while (!q.isEmpty()) {
            Pair cur = q.poll();
            vis[cur.x][cur.y] = true;
            if (decompose(cur.x) + decompose(cur.y) <= threshold) ++ans;
            else continue;
            //System.out.println(cur.x + ":" + cur.y);
            for (int i = 0; i < 4; ++i) {
                int nx = cur.x + dx[i], ny = cur.y + dy[i];
                if (0 <= nx && nx < rows && 0 <= ny && ny < cols && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.add(new Pair(nx, ny));
                }
            }
        }
        return ans;
    }
}