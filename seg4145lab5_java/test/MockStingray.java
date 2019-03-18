import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class MockStingray {

	private static final String HOSTNAME = "localhost";
	private static final int PORT = 9876; 
	private static Socket echoSocket;
	
	
	public static void main(String[] args) {
		try {
			echoSocket = new Socket(HOSTNAME, PORT);
			echoCommand();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				echoSocket.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}


	public static void echoCommand() {
		try {
		    PrintWriter out =
		        new PrintWriter(echoSocket.getOutputStream(), true);
		    BufferedReader in =
		        new BufferedReader(
		            new InputStreamReader(echoSocket.getInputStream()));
		    
		    char[] buffer = new char[20];
		    in.read(buffer);
		    if(!"quit!".equals(buffer.toString())) {
		    	System.out.print(buffer);
		    	System.out.print("\n");
		    	out.println("10.0");
		    	echoCommand();
		    }
		} catch (Exception e) {
			e.printStackTrace();
		}
	}	
}
