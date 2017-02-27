package cc.goozy.util;

import java.io.*;
import java.util.*;

public class TextFile extends ArrayList<String> {
	// read a file as a single string
	public static String read(String fileName) {
		StringBuilder sb = new StringBuilder();
		try {
			BufferedReader in = new BufferedReader(new FileReader(
				new File(fileName).getAbsolutePath()));
			try {
				String s;
				while ((s = in.readLine()) != null) {
					sb.append(s);
					sb.append('\n');
				}
			} finally {
				in.close();
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		return sb.toString();
	}
	
	// write a single file in one method call
	public static void write(String fileName, String text) {
		try {
			PrintWriter out = new PrintWriter(
				new File(fileName).getAbsolutePath());
			try {
				out.print(text);
			} finally {
				out.close();
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
	
	// Read a file, split by any regular expression
	public TextFile(String fileName, String spliter) {
		super(Arrays.asList(read(fileName).split(spliter)));
		// Regular expression split() often leaves an empty
		// String at the first position: 
		if (get(0).equals("")) remove(0);
	}
	
	// Normally read by lines:
	public TextFile(String fileName) {
		this(fileName, "\n");
	}
	
	public void write(String fileName) {
		try {
			PrintWriter out = new PrintWriter(
				new File(fileName).getAbsolutePath());
			try {
				for (String item : this) {
					out.println(item);
				}
			} finally {
				out.close();
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
}
