import java.io.File;
import java.io.IOException;

public class Main {
	public static void main(String[] args) throws IOException {
		File folder = new File("C:/Users/apple/Desktop/test");
		if (!folder.exists()) {
			System.out.println("Ŀ¼�����ڡ�������...");
			// ��ͬ�����ڵĸ���Ŀ¼һ�𴴽�
			folder.mkdirs();
		}
		
		File file = new File(folder, "test.txt");
		if (!file.exists())
			file.createNewFile();
		
		System.out.println(file.getAbsolutePath());
		System.out.println(file.getParent());
		
		//file.delete();

		for (String str : folder.list()) {
			System.out.println(str);
		}
		listAll(folder);
	}
	
	public static void listAll(File file) {
		if (file.isFile()) {
			System.out.println("�ļ�: " + file);
			return;
		}
		System.out.println("=========\nĿ¼: " + file);
		for (File subFile : file.listFiles()) {
			listAll(subFile);
		}
	}
}