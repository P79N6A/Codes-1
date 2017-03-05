import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {
	public static void main(String[] args) {
		try {
			Socket socket = new Socket("127.0.0.1", 2017);
			socket.setSoTimeout(60000);
			
			 /** ���Ϳͻ���׼���������Ϣ */
			// ��socket����õ������
			PrintWriter printWriter = new PrintWriter(socket.getOutputStream(), true);
			// �����������ַ��������Server
			BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
			printWriter.println(bufferedReader.readLine());
			// ˢ���������ʹServer�����յ����ַ���
            printWriter.flush();
            
            /** ���ڻ�ȡ����˴���������Ϣ */
            // ��Socket����õ�����������������Ӧ��BufferedReader����
            bufferedReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            // �������һ�ַ���
            String result = bufferedReader.readLine();
            System.out.println("Server say : " + result);

            /** �ر�Socket*/
            printWriter.close();
            bufferedReader.close();
            socket.close();
		} catch (Exception e) {
			System.out.println("Exception: " + e);
		}
	}
}
