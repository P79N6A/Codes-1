public class Hanoi {
    /*
     * n - 1个放在中间，大盘放到右边，再把n - 1个放右边
     */
    private static void hanoi(int n, char a, char b, char c) {
        if (n == 1) {
            System.out.println("Move " + a + " to " + c);
            return;
        }
        hanoi(n - 1, a, c, b);
        System.out.println("Move " + a + " to " + c);
        hanoi(n - 1, b, a, c);
    }

    public static void main(String args[]) {
        hanoi(3, 'A', 'B', 'C');
    }
}
