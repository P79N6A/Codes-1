import java.util.*;
import java.util.regex.*;

public class Main {
    public static void main(String[] args) {
    	String s = "hello everyone! Now I'm going to practice my skill. What? Go to.";
    	Pattern p = Pattern.compile("\\b[a-z]+");
    	Matcher m = p.matcher(s);
    	Set<String> st = new HashSet<>();
    	while (m.find()) {
    		st.add(m.group());
    	}
    	System.out.println("非重复的词有: " + st.size() + "个。");
    }
}