import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		String file = "C:/Users/apple/Desktop/test/test.txt";
		FileInputStream inputStream = new FileInputStream(file);
		FileOutputStream outputStream = new FileOutputStream("C:/Users/apple/Desktop/test/哈哈/out.txt");
		byte[] buf = new byte[1024];
		int len = -1;
		while ((len = inputStream.read(buf)) != -1) {
			outputStream.write(buf);
		}
		inputStream.close();
		outputStream.close();
	}
	
}