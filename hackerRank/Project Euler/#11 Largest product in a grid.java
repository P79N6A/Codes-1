import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    static int[][] grid;
    static long ans;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        grid = new int[20][20];
        for(int grid_i=0; grid_i < 20; grid_i++){
            for(int grid_j=0; grid_j < 20; grid_j++){
                grid[grid_i][grid_j] = in.nextInt();
            }
        }
        ans = 1;
        for (int i = 0; i < 17; ++i) {
            for (int j = 0; j < 17; ++j) {
                solve(i, j, 1, 1);
                solve(i, j, 0, 1);
                solve(i, j, 1, 0);
            }
        }
        for (int i = 0; i < 17; ++i) {
            for (int j = 19; j > 2; --j) {
                solve(i, j, 1, -1);
            }
        }
        for (int i = 17; i < 20; ++i) {
            for (int j = 0; j < 17; ++j) {
                solve(i, j, 0, 1);
            }
        }
        System.out.println(ans);
    }
    
    public static void solve(int x, int y, int addx, int addy) {
        int temp = 1;
        for (int i = 0; i < 4; ++i) {
            temp *= grid[x][y];
            x += addx;
            y += addy;
        }
        ans = Math.max(ans, temp);
    }
}