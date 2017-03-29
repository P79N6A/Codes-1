import java.util.Stack;

public class Solution {
    private Stack<Integer> stack = new Stack<>();
    private Stack<Integer> minStack = new Stack<>();
    private boolean first = true;
    public void push(int node) {
        stack.push(node);
        if (first) {
            minStack.push(node);
            first = false;
        }
        else if (!minStack.isEmpty() && node <= minStack.peek()) {
            minStack.push(node);
        }
    }
    
    public void pop() {
        int out = stack.pop();
        if (out == minStack.peek()) {
            minStack.pop();
            if (minStack.isEmpty()) {
                first = true;
            }
        }
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int min() {
        return minStack.peek();
    }
}