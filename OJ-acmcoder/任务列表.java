import java.util.Arrays;
import java.util.Scanner;

class Query implements Comparable<Query> {
	int time, id;
	
	public Query(int id) {
		this.id = id;
	}
	
	@Override
	public int compareTo(Query o) {
		return time - o.time;
	}
}

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), m = in.nextInt();
		int[] t = new int[n];
		for (int i = 0; i < n; ++i) {
			t[i] = in.nextInt();
		}
		Arrays.sort(t);
		int[] ans = new int[m];
		Query[] query = new Query[m];
		for (int i = 0; i < m; ++i) {
			query[i] = new Query(i);
			query[i].time = in.nextInt();
		}
		Arrays.sort(query);
		int j = 0;
		for (int i = 0; i < m; ++i) {
			int time = query[i].time;
			while (j < n && time >= t[j]) ++j;
			if (j == n)
				ans[query[i].id] = t[n - 1] + 1;
			else {
				if (j == 0) ans[query[i].id] = time;
				else {
					if (t[j - 1] + 1 != t[j])  ans[query[i].id] = Math.max(t[j - 1] + 1, time);
					else {
						while (j < n && t[j - 1] + 1 == t[j]) ++j;
						ans[query[i].id] = t[j - 1] + 1;
					}
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			System.out.println(ans[i]);
		}
		in.close();
	}
}