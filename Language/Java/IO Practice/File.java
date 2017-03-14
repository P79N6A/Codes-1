import java.io.File;
import java.io.IOException;

public class Main {
	public static void main(String[] args) throws IOException {
		File folder = new File("C:/Users/apple/Desktop/test");
		if (!folder.exists()) {
			System.out.println("目录不存在。创建中...");
			// 连同不存在的父级目录一起创建
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
			System.out.println("文件: " + file);
			return;
		}
		System.out.println("=========\n目录: " + file);
		for (File subFile : file.listFiles()) {
			listAll(subFile);
		}
	}
}