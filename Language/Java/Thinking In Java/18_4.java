package src;

import java.io.*;
import java.util.regex.Pattern;

public class Solution {
	
	public static void main(String[] args) {
		String path = ".", reg = ".*\\..*";
		if (path == "") 
			return;
		
		File target = new File(path);
		File[] list = null;
		if (reg == "" || reg == null) {
			list = target.listFiles();
		}
		else {
			list = target.listFiles(new FilenameFilter() {
				private Pattern pattern = Pattern.compile(reg);
				@Override
				public boolean accept(File dir, String name) {
					// TODO Auto-generated method stub
					return pattern.matcher(name).matches();
				}
			});
		}
		
		int result = 0, num = 0;
		for (File file : list) {
			if (file.isDirectory()) continue;
			++num;
			result += file.length();
		}
		System.out.println(num + " file(s), " + result + " bytes in total.");
	}
}
