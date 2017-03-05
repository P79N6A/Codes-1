import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.*;

public class Server {
	public static void main(String[] args) {
		try {
            /** ����ServerSocket*/
            // ����һ��ServerSocket�ڶ˿�2017�����ͻ�����
            ServerSocket serverSocket = new ServerSocket(2017);
            while (true) {
                // ���������ܵ���Socket������,�����������һ��Socket���󣬲�����ִ��
                Socket socket = serverSocket.accept();

                /** ��ȡ�ͻ��˴�������Ϣ */
                // ��Socket����õ�����������������Ӧ��BufferedReader����
                BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                // ��ȡ�ӿͻ��˶�����ַ���
                String result = bufferedReader.readLine();
                System.out.println("Client say : " + result);

                /** ���ͷ����׼������� */
                // ��Socket����õ��������������PrintWriter����
                PrintWriter printWriter = new PrintWriter(socket.getOutputStream());
                printWriter.print("hello Client, I am Server!");
                printWriter.flush();

                /** �ر�Socket*/
                printWriter.close();
                bufferedReader.close();
                socket.close();
            }
        } catch (Exception e) {
            System.out.println("Exception:" + e);
        }finally{
//            serverSocket.close();
        }
	}
}
