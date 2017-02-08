import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
    	String s = "Java now has regular expression";
    	String[] test = {"^Java", "\\Breg.*", "n.w\\s+h(a|i)s", "s?", 
    			"s*", "s+", "s{4}", "s{1}", "s{0,3}"};
    	for (String ea : test) {
    		System.out.println(ea + ": " + Pattern.compile(ea).matcher(s).matches());
    	}
    }
}