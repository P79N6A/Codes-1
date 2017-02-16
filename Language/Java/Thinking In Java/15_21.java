import java.util.*;

class ClassTypeCapture {
	Map<String,Class<?>> types = new HashMap<String,Class<?>>();
	public Object createNew(String typename) {
		Class<?> cl = types.get(typename);
		try {
			return cl.newInstance();
		} catch(NullPointerException e) {
			System.out.println("Not a registered typename: " + typename);
		} catch(Exception e) {
			System.out.println(e.toString());
		}
		return null;
	}
	
	public void addType(String typename, Class<?> kind) {
		//System.out.println(kind);
		types.put(typename, kind);
	}
}

public class Solution {
	public static void main(String[] args) {
		ClassTypeCapture ctt = new ClassTypeCapture();
		ctt.addType("String", String.class);
		System.out.println(ctt.createNew("String").getClass());
		ctt.createNew("BigInteger");
		ctt.createNew("String");
	}
}