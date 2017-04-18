import java.util.HashMap;

public class Main {
	// 九十亿两千万两千零七
	// 十一
	// 六千零五亿九千九百零二
	
	private static final String[] digit = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};
	private static final String[] unitSection = {"", "万", "亿", "万亿"};
	private static final String[] unitChar = {"", "十", "百", "千"};
	private static final HashMap<String, Long> mp = new HashMap<>();
	
	public static void main(String[] args) {
		for (int i = 0; i < 10; ++i) {
			mp.put(digit[i], (long)i);
		}
		for (int i = 1; i < 4; ++i) {
			mp.put(unitChar[i], (long)Math.pow(10, i));
			mp.put(unitSection[i], (long)Math.pow(10, i * 4));
		}
		
		String s = toChinese(10);
		System.out.println(s);
		System.out.println(toDigit(s));
	}
	
	public static long toDigit(String s) {
		long ret = 0;
		long unit = 1; // 单位
		char[] str = s.toCharArray();
		for (int i = str.length - 1; i >= 0; --i) {
			long cur = mp.get(String.valueOf(str[i]));
			if (cur >= 10) {
				if (cur > unit) {
					unit = cur;
				}
				else unit *= cur;
			}
			else {
				ret += cur * unit;
			}
		}
		if (ret == 0 && unit != 0) ret = unit;
		return ret;
	}
	
	// 每10000作为一个小节来计算
	public static String toChinese(long num) {
		if (num == 0) return digit[0];
		StringBuilder ret = new StringBuilder();
		int pos = 0;
		boolean needZero = false;
		while (num > 0) {
			int cur = (int)(num % 10000);
			if (needZero) {
				ret.insert(0, digit[0]);
			}
			ret.insert(0, sectionToChinese(cur) + 
					(cur == 0 ? "" : unitSection[pos]));
			needZero = (0 < cur && cur < 1000);
			++pos;
			num /= 10000;
		}
		return ret.toString();
	}
	
	private static String sectionToChinese(int num) {
		StringBuilder ret = new StringBuilder();
		int pos = 0;
		boolean zero = false; // 是否可以使用零
		while (num > 0) {
			int cur = num % 10;
			if (cur == 0) {
				if (zero) {
					zero = false;
					ret.insert(0, digit[0]);
				}
			}
			else {
				zero = true; // 至少一个数非零
				ret.insert(0, digit[cur] + unitChar[pos]);
			}
			++pos;
			num /= 10;
		}
		return ret.toString();
	}
}