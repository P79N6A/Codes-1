import java.io.*;
import java.util.logging.Logger;

class MyException extends Exception {
    private static Logger logger = Logger.getLogger("MyException");
    public void print() {
        StringWriter trace = new StringWriter();
        printStackTrace(new PrintWriter(trace));
        logger.severe(trace.toString());
    }
}


public class Solution {
    public static void main(String[] args) {
        try {
            throw new MyException();
        }catch (MyException e) {
            e.print();
        }
    }
}