import java.util.Scanner;

class Taxi {
	int x, y;
}

public class Main {
	
	private static long gx, gy, walk, tax;
	
	private static long cal(Taxi x) {
		return (Math.abs(x.x - gx) + Math.abs(x.y - gy)) * tax 
				+ (Math.abs(x.x) + Math.abs(x.y)) * walk;
	}
	
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Taxi[] taxi = new Taxi[n];
        for(int i = 0; i < n; i++){
        	taxi[i] = new Taxi();
        	taxi[i].x = sc.nextInt();
        	taxi[i].y = sc.nextInt();
        } 
        gx = sc.nextInt();
        gy = sc.nextInt();
        walk = sc.nextInt();
        tax = sc.nextInt();
        
        long ans = (Math.abs(gx) + Math.abs(gy)) * walk;
        for (int i = 0; i < n; ++i) {
        	ans = Math.min(ans, cal(taxi[i]));
        }
        
        System.out.println(ans);
        sc.close();
	}
}