import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		String file = "C:/Users/apple/Desktop/test/test.txt";
		BufferedInputStream inputStream = new BufferedInputStream(new FileInputStream(file));
		BufferedOutputStream outputStream = new BufferedOutputStream(new FileOutputStream("C:/Users/apple/Desktop/test/哈哈/out.txt"));
		byte[] buf = new byte[1024];
		int len = -1;
		while ((len = inputStream.read(buf)) != -1) {
			System.out.println(new String(buf, 0, len));
			outputStream.write(buf);
		}
		inputStream.close();
		outputStream.close();
	}
	
}