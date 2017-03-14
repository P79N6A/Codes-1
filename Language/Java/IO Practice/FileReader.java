import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		String file = "C:/Users/apple/Desktop/test/test.txt";
		FileReader inputStream = new FileReader(file);
		FileWriter outputStream = new FileWriter("C:/Users/apple/Desktop/test/哈哈/out.txt");
		char[] buf = new char[1024];
		int len = -1;
		while ((len = inputStream.read(buf)) != -1) {
			System.out.println(new String(buf, 0, len));
			outputStream.write(buf, 0, len);
		}
		System.out.println("好了~");
		inputStream.close();
		outputStream.close();
	}
	
}