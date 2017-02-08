public class Main {
    public static void main(String[] args) {
    	String s = "A%-10.2s 123.";
    	String s2 = "a%-10.2s 123.";
    	String s3 = "A%-10.2s 123=";
    	String reg = "^[A-Z].*\\.";
    	System.out.println("s : " + s.matches(reg));
    	System.out.println("s2: " + s2.matches(reg));
    	System.out.println("s3: " + s3.matches(reg));
    }
}