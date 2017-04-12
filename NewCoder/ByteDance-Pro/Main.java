import java.util.ArrayList;

public class Main {
    
    // 判断是否找到合理的排列满足题意
    static boolean hasAns = false;
    
    // rank[i]：学校i的排名是rank[i]
    private static int[] rank = new int[5];
    
    // 存放每个人的猜测结果
    private static ArrayList<Guess>[] guess = new ArrayList[5];
    
    public static void main(String[] args) {
        // 初始化每个学校的猜测
        for (int i = 0; i < 5; ++i) {
            guess[i] = new ArrayList<>();
        }
    	// A校的猜测：
    	guess[0].add(new Guess('E', 0));
    	// B校的猜测：
    	guess[1].add(new Guess('B', 1));
    	// C校的猜测：
    	guess[2].add(new Guess('A', 4));
    	// D校的猜测：
    	guess[3].add(new Guess('C', 1));
    	guess[3].add(new Guess('C', 2));
            guess[3].add(new Guess('C', 3));
            guess[3].add(new Guess('C', 4));
    	// E校的猜测：
    	guess[4].add(new Guess('D', 0));
        
        // 学校排名初始排列
        char[] rankString = {'A', 'B', 'C', 'D', 'E'};
        
        // 枚举所有排列
        permutation(rankString, 0);
        
        if (hasAns) {
            System.out.println("最终排名结果如下:");
            for (int i = 0; i < 5; ++i) {
                System.out.println((char)(i + 'A') + ": " + (rank[i] + 1));
            }
        }
        else {
            System.out.println("无法找到满足答案的序列。");
        }
    }
    
    
    /**
     * 枚举全排列
     * @param rankString 学校名字对应的等级排列
     * @param pos 当前考虑的位置
     * 结束条件: 当排列长度达到rankString长度时,结束递归
     */
    private static void permutation(char[] rankString, int pos) {
        // 如果已经找到答案了,就不用继续递归下去
        if (hasAns) return;
        if (pos == rankString.length) {
            // 得出全排列后,通过solve函数判断该排列是否符合题意
            if (solve(rankString)) {
                hasAns = true;
                return;
            }
            return;
        }
        // 考虑当前位置pos应该放入什么字符,放入的字符自动放到pos位置上,接着向pos+1递归
        for (int i = pos; i < rankString.length; ++i) {
            swap(rankString, pos, i);
            permutation(rankString, pos + 1);
            swap(rankString, pos, i);
        }
    }
    

    /**
     * 判断排列的等级是否符合题意
     * @param rankString 学校名字对应的等级排列
     * @return 符合返回true,否则false
     */
    private static boolean solve(char[] rankString) {
        // 根据排名结果给rank数组赋值
        for (int i = 0; i < rankString.length; ++i) {
            rank[rankString[i] - 'A'] = i;
        }
        // E不能为第二名或者第三名
        if (rank[4] == 1 || rank[4] == 2) return false;
        
        // 验证别人说的话是否是正确的，从第i名开始验证
        for (int i = 0; i < 5; ++i) {
            // 排名第i的学校
            int cur = rankString[i] - 'A';
            for (int j = 0; j < guess[cur].size(); ++j) {
                char name = guess[cur].get(j).name;
                int rnk = guess[cur].get(j).rank;
                // 如果是前两名，那么他说的话一定正确
                if (i < 2) {
                    // 矛盾，返回false
                    if (rank[name - 'A'] != rnk)
                            return false;
                }
                // 如果是后三名，那么他说的话一定错误
                else {
                    // 矛盾，返回false
                    if (rank[name - 'A'] == rnk) 
                            return false;
                }
            }
        }
        // 所有人说的话都满足了,符合条件
        return true;
    }
    

    /**
     * 交换char[]数组的两个元素
     * @param s 需要被交换的元素所在数组
     * @param x 第一个需要交换的位置
     * @param y 第二个需要交换的位置
     */
    private static void swap(char[] s, int x, int y) {
        char temp = s[x];
        s[x] = s[y];
        s[y] = temp;
    }
}

// Guess存放单个猜测，name是学校名字
// rnk是猜测的这个学校的排名，从0开始算排名
class Guess {
    public char name;
    public int rank;
    public Guess(char name, int rank) {
        this.name = name;
        this.rank = rank;
    }
}