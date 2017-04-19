import java.util.*;

public class SetOfStacks {
    public ArrayList<ArrayList<Integer>> setOfStacks(int[][] ope, int size) {
        ArrayList<ArrayList<Integer>> stack = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < ope.length; ++i) {
            if (ope[i][0] == 1) {
                push(stack, ope[i][1], size);
            }
            else {
                pop(stack);
            }
        }
        return stack;
    }
    
    public void push(ArrayList<ArrayList<Integer>> stack, int val, int size) {
        int cur = stack.size() - 1;
        if (cur == -1 || stack.get(cur).size() == size) {
            stack.add(new ArrayList<Integer>());
            ++cur;
        }
        stack.get(cur).add(val);
    }
    
    public void pop(ArrayList<ArrayList<Integer>> stack) {
        int cur = stack.size() - 1;
        if (stack.get(cur).size() == 1) {
            stack.remove(cur);
        }
        else {
            stack.get(cur).remove(stack.get(cur).size() - 1);
        }
    }
}