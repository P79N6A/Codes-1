import java.util.*;


public class Solution {
    public static void main(String[] args) {
        LinkedList<Integer> ll = new LinkedList<>();
        ListIterator<Integer> it = ll.listIterator();
        int[] item = new int[]{3, 5, 1, 2, 4};
        for (int i : item) {
            int step = ll.size() / 2;
            while (it.nextIndex() < step || it.previousIndex() > step) {
                if (it.nextIndex() < step)
                    it.next();
                if (it.previousIndex() > step)
                    it.previous();
            }
            it.add(i);
            it.previous();
            System.out.println(ll);
        }
    }
}