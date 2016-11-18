import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int k = in.nextInt();
            String num = in.next();
            int sum = 0, mx = 0;
            for (int i = 0; i < num.length() - k; ++i) {
                for (int j = 0; j < k; ++j) {
                    int cur = num.charAt(i + j) - '0';
                    if (j == 0) sum = cur;
                    else sum *= cur;
                }
                mx = Math.max(mx, sum);
            }
            System.out.println(mx);
        }
    }
}
